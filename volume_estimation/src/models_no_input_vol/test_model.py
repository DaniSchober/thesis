from tqdm import tqdm
import torch
from sklearn.model_selection import train_test_split
from src.data.dataloader import VesselCaptureDataset
from torch.utils.data import DataLoader
import torch.nn as nn
from src.models_no_input_vol.model_new import VolumeNet
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import numpy as np

data_dir = "data/processed"

# Load the dataset
dataset = VesselCaptureDataset(data_dir)
print(f"Loaded {len(dataset)} samples")

# Split the dataset into training and test data
train_data, test_data = train_test_split(dataset, test_size=0.1, random_state=42)



# Set up the data loader and training parameters for the test data
test_loader = DataLoader(test_data, batch_size=1, shuffle=False)
test_size = len(test_data)

print("Size test set: ", test_size)

# load model from models/model_new.py
model = VolumeNet()
model.load_state_dict(torch.load("models/volume_model.pth"))
model.eval()

squared_error_liquid_total = 0
squared_error_vessel_total = 0
squared_error_liquid_array = []
predicted_vol_liquid_list = []
actual_vol_liquid_list = []
vessel_name_list = []

# create output folder for images with volume estimation
import os
output_folder = "output_no_vol_input"
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

with torch.no_grad():
    for i, data in enumerate(test_loader):
        vessel_depth = data["vessel_depth"]
        liquid_depth = data["liquid_depth"]
        vessel_name = data["vessel_name"]

        #vessel_depth = data["segmentation_vessel"]
        #liquid_depth = data["segmentation_liquid"]
        

        #vessel_vol = data["vol_vessel"]
        #vessel_vol = vessel_vol.view(vessel_depth.shape[0], 1, 1).repeat(1, 160, 214)
        #inputs = torch.cat([vessel_depth, liquid_depth], dim=1)
        #inputs = data["depth_image"]
        targets = data["vol_liquid"]
        targets = targets.float()

        print("Liquid_depth shape: ", liquid_depth.shape)
        outputs = model(vessel_depth, liquid_depth)
        
        outputs = outputs.squeeze(0)
        targets = targets.squeeze(0)
        print("Sample ", i, ":", outputs, targets)

        # first element of output is volume of liquid, second is volume of vessel
        predicted_vol_liquid = outputs.item()
        actual_vol_liquid = targets.item()
        #vessel_name = vessel_name.item()

        # save them in a list
        predicted_vol_liquid_list.append(predicted_vol_liquid)
        actual_vol_liquid_list.append(actual_vol_liquid)
        # convert vessel name from list object to string
        vessel_name = vessel_name[0]

        vessel_name_list.append(vessel_name)
        #predicted_vol_vessel = outputs[1].item()
        #actual_vol_vessel = targets[1].item()

        # open image from test set and draw volume estimation on it
        import cv2
        #img = cv2.imread(data["image_path"])
        print("Image path: ", data["image_path"][0])
        img = cv2.imread(data["image_path"][0])

        # draw volume estimation on image
        cv2.putText(img, "Volume liquid: " + str(predicted_vol_liquid), (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
        cv2.putText(img, "Actual volume liquid: " + str(actual_vol_liquid), (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

        # save image with volume estimation
        cv2.imwrite(output_folder + "/image_" + str(i) + ".png", img)

        # calculate squared error for item
        squared_error_liquid = (predicted_vol_liquid - actual_vol_liquid) ** 2
        #squared_error_vessel = (predicted_vol_vessel - actual_vol_vessel) ** 2

        # add squared error to total
        squared_error_liquid_total += squared_error_liquid

        squared_error_liquid_array = np.append(squared_error_liquid_array, squared_error_liquid**0.5)
        #squared_error_vessel_total += squared_error_vessel
    
    # calculate RMSE for test set
    rmse_liquid = (squared_error_liquid_total / test_size) ** 0.5
    #rmse_vessel = (squared_error_vessel_total / test_size) ** 0.5

    # plot histogram of squared errors
    plt.hist(squared_error_liquid_array, bins=100)
    plt.show()
    # xlabel
    plt.xlabel("RSE")
    # ylabel
    plt.ylabel("Frequency")

    # save histogram of squared errors
    plt.savefig("squared_error_liquid.png")

    # plot predicted volume vs actual volume in scatter plot with color depending on vessel name
    # get unique vessel names
    vessel_name_list_unique = np.unique(vessel_name_list)
    print(vessel_name_list)
    # plot scatter plot
    for i in range(len(vessel_name_list_unique)):
        # get indices of vessel name
        indices = [j for j, x in enumerate(vessel_name_list) if x == vessel_name_list_unique[i]]
        print("Indices: ", indices)
        # get predicted and actual volume for vessel name
        predicted_vol_liquid_list_vessel = [predicted_vol_liquid_list[j] for j in indices]
        actual_vol_liquid_list_vessel = [actual_vol_liquid_list[j] for j in indices]
        print("Vessel name: ", vessel_name_list_unique[i])
        print("Predicted volume: ", predicted_vol_liquid_list_vessel)
        print("Actual volume: ", actual_vol_liquid_list_vessel)
        # plot scatter plot
        plt.scatter(actual_vol_liquid_list_vessel, predicted_vol_liquid_list_vessel, label=vessel_name_list_unique[i])
    plt.legend()

    #plt.scatter(actual_vol_liquid_list, predicted_vol_liquid_list, c=vessel_name_list, cmap=cm.get_cmap('jet', 10))

    #plt.scatter(actual_vol_liquid_list, predicted_vol_liquid_list)
    # xlabel
    plt.xlabel("Actual volume")
    # ylabel
    plt.ylabel("Predicted volume")
    plt.show()



    print("RMSE liquid: ", rmse_liquid)
    #print("RMSE vessel: ", rmse_vessel)







