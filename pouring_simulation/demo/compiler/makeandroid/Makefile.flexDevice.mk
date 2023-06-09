# Makefile generated by XPJ for android
-include Makefile.custom
ProjectName = flexDevice
flexDevice_cppfiles   += ./../../../src/device/PhysXDevice.cpp
flexDevice_cppfiles   += ./../../../src/device/flexDevice.cpp

flexDevice_cpp_release_dep    = $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(patsubst %.cpp, %.cpp.P, $(flexDevice_cppfiles)))))
flexDevice_cc_release_dep    = $(addprefix $(DEPSDIR)/, $(subst ./, , $(subst ../, , $(patsubst %.cc, %.cc.release.P, $(flexDevice_ccfiles)))))
flexDevice_c_release_dep      = $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(patsubst %.c, %.c.P, $(flexDevice_cfiles)))))
flexDevice_release_dep      = $(flexDevice_cpp_release_dep) $(flexDevice_cc_release_dep) $(flexDevice_c_release_dep)
-include $(flexDevice_release_dep)
flexDevice_release_hpaths    := 
flexDevice_release_hpaths    += ./../../..
flexDevice_release_hpaths    += ./../../../../../../external/android-ndk/android-ndk-r10e-linux/platforms/android-15/arch-arm/usr/include
flexDevice_release_hpaths    += ./../../../../../../external/android-ndk/android-ndk-r10e-linux/sources/cxx-stl/stlport/stlport
flexDevice_release_hpaths    += ./../../../../../../external/CUDA/cuda-6.0-linux/targets/armv7-linux-androideabi/include
flexDevice_release_lpaths    := 
flexDevice_release_lpaths    += ./../../../../../../external/CUDA/cuda-6.0-linux/targets/armv7-linux-androideabi/lib
flexDevice_release_lpaths    += ./../../../lib/android
flexDevice_release_lpaths    += ./../../../../../../external/android-ndk/android-ndk-r10e-linux/sources/cxx-stl/stlport/libs/armeabi-v7a
flexDevice_release_defines   := $(flexDevice_custom_defines)
flexDevice_release_defines   += android
flexDevice_release_defines   += ANDROID=1
flexDevice_release_defines   += ANDROID_PLAT=1
flexDevice_release_defines   += DISABLE_IMPORTGL
flexDevice_release_libraries := 
flexDevice_release_common_cflags	:= $(flexDevice_custom_cflags)
flexDevice_release_common_cflags    += -MMD
flexDevice_release_common_cflags    += $(addprefix -D, $(flexDevice_release_defines))
flexDevice_release_common_cflags    += $(addprefix -I, $(flexDevice_release_hpaths))
flexDevice_release_cflags	:= $(flexDevice_release_common_cflags)
flexDevice_release_cflags  += -Wall -std=c++11 -fpermissive -fno-strict-aliasing -fno-rtti -fno-exceptions
flexDevice_release_cflags  += -O3 -ffast-math
flexDevice_release_cppflags	:= $(flexDevice_release_common_cflags)
flexDevice_release_cppflags  += -Wall -std=c++11 -fpermissive -fno-strict-aliasing -fno-rtti -fno-exceptions
flexDevice_release_cppflags  += -O3 -ffast-math
flexDevice_release_lflags    := $(flexDevice_custom_lflags)
flexDevice_release_lflags    += $(addprefix -L, $(flexDevice_release_lpaths))
flexDevice_release_lflags    += -Wl,--start-group $(addprefix -l, $(flexDevice_release_libraries)) -Wl,--end-group
flexDevice_release_objsdir  = $(OBJS_DIR)/flexDevice_release
flexDevice_release_cpp_o    = $(addprefix $(flexDevice_release_objsdir)/, $(subst ./, , $(subst ../, , $(patsubst %.cpp, %.cpp.o, $(flexDevice_cppfiles)))))
flexDevice_release_cc_o    = $(addprefix $(flexDevice_release_objsdir)/, $(subst ./, , $(subst ../, , $(patsubst %.cc, %.cc.o, $(flexDevice_ccfiles)))))
flexDevice_release_c_o      = $(addprefix $(flexDevice_release_objsdir)/, $(subst ./, , $(subst ../, , $(patsubst %.c, %.c.o, $(flexDevice_cfiles)))))
flexDevice_release_obj      = $(flexDevice_release_cpp_o) $(flexDevice_release_cc_o) $(flexDevice_release_c_o)
flexDevice_release_bin      := ./../../../lib/android/libflexDevice_x64.a

clean_flexDevice_release: 
	@$(ECHO) clean flexDevice release
	@$(RMDIR) $(flexDevice_release_objsdir)
	@$(RMDIR) $(flexDevice_release_bin)
	@$(RMDIR) $(DEPSDIR)/flexDevice/release

build_flexDevice_release: postbuild_flexDevice_release
postbuild_flexDevice_release: mainbuild_flexDevice_release
mainbuild_flexDevice_release: prebuild_flexDevice_release $(flexDevice_release_bin)
prebuild_flexDevice_release:

$(flexDevice_release_bin): $(flexDevice_release_obj) 
	mkdir -p `dirname ./../../../lib/android/libflexDevice_x64.a`
	@$(AR) rcs $(flexDevice_release_bin) $(flexDevice_release_obj)
	$(ECHO) building $@ complete!

flexDevice_release_DEPDIR = $(dir $(@))/$(*F)
$(flexDevice_release_cpp_o): $(flexDevice_release_objsdir)/%.o:
	$(ECHO) flexDevice: compiling release $(filter %$(strip $(subst .cpp.o,.cpp, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cppfiles))...
	mkdir -p $(dir $(@))
	$(CXX) $(flexDevice_release_cppflags) -c $(filter %$(strip $(subst .cpp.o,.cpp, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cppfiles)) -o $@
	@mkdir -p $(dir $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .cpp.o,.cpp, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cppfiles))))))
	cp $(flexDevice_release_DEPDIR).d $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .cpp.o,.cpp, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cppfiles))))).P; \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $(flexDevice_release_DEPDIR).d >> $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .cpp.o,.cpp, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cppfiles))))).P; \
	  rm -f $(flexDevice_release_DEPDIR).d

$(flexDevice_release_cc_o): $(flexDevice_release_objsdir)/%.o:
	$(ECHO) flexDevice: compiling release $(filter %$(strip $(subst .cc.o,.cc, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_ccfiles))...
	mkdir -p $(dir $(@))
	$(CXX) $(flexDevice_release_cppflags) -c $(filter %$(strip $(subst .cc.o,.cc, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_ccfiles)) -o $@
	mkdir -p $(dir $(addprefix $(DEPSDIR)/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .cc.o,.cc, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_ccfiles))))))
	cp $(flexDevice_release_DEPDIR).d $(addprefix $(DEPSDIR)/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .cc.o,.cc, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_ccfiles))))).release.P; \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $(flexDevice_release_DEPDIR).d >> $(addprefix $(DEPSDIR)/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .cc.o,.cc, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_ccfiles))))).release.P; \
	  rm -f $(flexDevice_release_DEPDIR).d

$(flexDevice_release_c_o): $(flexDevice_release_objsdir)/%.o:
	$(ECHO) flexDevice: compiling release $(filter %$(strip $(subst .c.o,.c, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cfiles))...
	mkdir -p $(dir $(@))
	$(CC) $(flexDevice_release_cflags) -c $(filter %$(strip $(subst .c.o,.c, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cfiles)) -o $@ 
	@mkdir -p $(dir $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .c.o,.c, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cfiles))))))
	cp $(flexDevice_release_DEPDIR).d $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .c.o,.c, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cfiles))))).P; \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $(flexDevice_release_DEPDIR).d >> $(addprefix $(DEPSDIR)/flexDevice/release/, $(subst ./, , $(subst ../, , $(filter %$(strip $(subst .c.o,.c, $(subst $(flexDevice_release_objsdir),, $@))), $(flexDevice_cfiles))))).P; \
	  rm -f $(flexDevice_release_DEPDIR).d

clean_flexDevice:  clean_flexDevice_release
	rm -rf $(DEPSDIR)

export VERBOSE
ifndef VERBOSE
.SILENT:
endif
