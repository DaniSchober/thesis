#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
//
// Buffer Definitions: 
//
// cbuffer constBuf
// {
//
//   struct PointShaderConst
//   {
//       
//       float4x4 modelview;            // Offset:    0
//       float4x4 projection;           // Offset:   64
//       float4x4 lightTransform;       // Offset:  128
//       float4 colors[8];              // Offset:  192
//       float4 shadowTaps[12];         // Offset:  320
//       float3 lightPos;               // Offset:  512
//       float _pad0;                   // Offset:  524
//       float3 lightDir;               // Offset:  528
//       float _pad1;                   // Offset:  540
//       float pointRadius;             // Offset:  544
//       float pointScale;              // Offset:  548
//       float spotMin;                 // Offset:  552
//       float spotMax;                 // Offset:  556
//       int mode;                      // Offset:  560
//       int _pad2[3];                  // Offset:  576
//
//   } gParams;                         // Offset:    0 Size:   612
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// constBuf                          cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// POSITION                 0   xyzw        0     NONE   float   xyzw
// DENSITY                  0   x           1     NONE   float   x   
// PHASE                    0   x           2     NONE     int   x   
// VERTEX                   0   xyzw        3     NONE   float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_POSITION              0   xyzw        0      POS   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyzw        2     NONE   float   xyzw
// TEXCOORD                 2   xyzw        3     NONE   float   xyzw
// TEXCOORD                 3   xyzw        4     NONE   float   xyzw
// TEXCOORD                 4   xyzw        5     NONE   float   xyzw
// TEXCOORD                 5   xyzw        6     NONE   float   xyzw
//
gs_5_0
dcl_globalFlags refactoringAllowed
dcl_immediateConstantBuffer { { 0, 1.000000, 0, 0},
                              { 0, 0, 0, 0},
                              { 1.000000, 1.000000, 0, 0},
                              { 1.000000, 0, 0, 0} }
dcl_constantbuffer cb0[36], dynamicIndexed
dcl_input v[1][0].xyzw
dcl_input v[1][1].x
dcl_input v[1][2].x
dcl_input v[1][3].xyzw
dcl_temps 8
dcl_indexableTemp x0[6], 4
dcl_inputprimitive point 
dcl_stream m0
dcl_outputtopology trianglestrip 
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xyzw
dcl_output o3.xyzw
dcl_output o4.xyzw
dcl_output o5.xyzw
dcl_output o6.xyzw
dcl_maxout 4
mov x0[3].w, l(0)
add r0.x, cb0[34].x, cb0[34].x
mul r0.yzw, cb0[33].xxyz, cb0[34].xxxx
mad r0.yzw, -r0.yyzw, l(0.000000, 2.000000, 2.000000, 2.000000), v[0][3].xxyz
mul r1.xyzw, r0.zzzz, cb0[9].xyzw
mad r1.xyzw, cb0[8].xyzw, r0.yyyy, r1.xyzw
mad r1.xyzw, cb0[10].xyzw, r0.wwww, r1.xyzw
add r1.xyzw, r1.xyzw, cb0[11].xyzw
mul r2.xyzw, cb0[1].xyzw, cb0[33].yyyy
mad r2.xyzw, cb0[0].xyzw, cb0[33].xxxx, r2.xyzw
mad r2.xyzw, cb0[2].xyzw, cb0[33].zzzz, r2.xyzw
lt r0.y, v[0][1].x, l(0.000000)
mad r3.xyz, v[0][1].xxxx, l(0.000000, -0.900000, 0.000000, 0.000000), l(0.100000, 0.100000, 1.000000, 0.000000)
mad r4.xyz, v[0][1].xxxx, l(-0.900000, -0.800000, 0.000000, 0.000000), l(1.000000, 1.000000, 1.000000, 0.000000)
ieq r0.zw, l(0, 0, 1, 2), cb0[35].xxxx
mul r3.w, l(0.050000), v[0][3].w
mov_sat r5.xyz, r3.wwww
and r3.w, l(7), v[0][2].x
add r6.xyz, cb0[r3.w + 12].xyzx, cb0[r3.w + 12].xyzx
mad r7.xyz, -cb0[r3.w + 12].xyzx, l(2.000000, 2.000000, 2.000000, 0.000000), l(1.000000, 1.000000, 1.000000, 0.000000)
mad r6.xyz, r7.xyzx, l(0.100000, 0.100000, 0.100000, 0.000000), r6.xyzx
movc r3.xyz, r0.yyyy, r3.xyzx, r4.xyzx
mov r0.y, l(0)
loop 
  ige r3.w, r0.y, l(4)
  breakc_nz r3.w
  add r4.xy, l(-0.500000, -0.500000, 0.000000, 0.000000), icb[r0.y + 0].xyxx
  mad r4.xy, r0.xxxx, r4.xyxx, v[0][0].xyxx
  mul r7.xyzw, r4.yyyy, cb0[5].xyzw
  mad r4.xyzw, cb0[4].xyzw, r4.xxxx, r7.xyzw
  mad r4.xyzw, cb0[6].xyzw, v[0][0].zzzz, r4.xyzw
  mad r4.xyzw, cb0[7].xyzw, v[0][0].wwww, r4.xyzw
  add r3.w, l(1.000000), -icb[r0.y + 0].y
  if_nz r0.z
    mov r7.xyz, r3.xyzx
  else 
    if_nz r0.w
      mov x0[3].w, r5.z
      mov r7.xyz, r5.xyzx
    else 
      mov r7.xyz, r6.xyzx
    endif 
  endif 
  mov r5.w, x0[3].w
  mov o0.xyzw, r4.xyzw
  mov o1.x, icb[r0.y + 0].x
  mov o1.y, r3.w
  mov o1.zw, l(0,0,0,0)
  mov o2.xyzw, r1.xyzw
  mov o3.xyzw, r2.xyzw
  mov o4.xyz, r7.xyzx
  mov o4.w, r5.w
  mov o5.xyz, v[0][3].xyzx
  mov o5.w, l(0)
  mov o6.xyz, v[0][0].xyzx
  mov o6.w, l(0)
  emit_stream m0
  iadd r0.y, r0.y, l(1)
endloop 
ret 
// Approximately 60 instruction slots used
#endif

const BYTE g_pointGS[] =
{
     68,  88,  66,  67,  83, 238, 
     66, 156,  86, 118, 105,  62, 
     85, 224, 176, 224, 229,   4, 
    226, 151,   1,   0,   0,   0, 
    188,  13,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    176,   3,   0,   0,  64,   4, 
      0,   0,  44,   5,   0,   0, 
     32,  13,   0,   0,  82,  68, 
     69,  70, 116,   3,   0,   0, 
      1,   0,   0,   0, 104,   0, 
      0,   0,   1,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
     83,  71,   0,   1,   0,   0, 
     64,   3,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0,  99, 111, 110, 115, 
    116,  66, 117, 102,   0, 171, 
    171, 171,  92,   0,   0,   0, 
      1,   0,   0,   0, 128,   0, 
      0,   0, 112,   2,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 168,   0,   0,   0, 
      0,   0,   0,   0, 100,   2, 
      0,   0,   2,   0,   0,   0, 
     28,   3,   0,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    103,  80,  97, 114,  97, 109, 
    115,   0,  80, 111, 105, 110, 
    116,  83, 104,  97, 100, 101, 
    114,  67, 111, 110, 115, 116, 
      0, 109, 111, 100, 101, 108, 
    118, 105, 101, 119,   0, 102, 
    108, 111,  97, 116,  52, 120, 
     52,   0,   3,   0,   3,   0, 
      4,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 203,   0, 
      0,   0, 112, 114, 111, 106, 
    101,  99, 116, 105, 111, 110, 
      0, 108, 105, 103, 104, 116, 
     84, 114,  97, 110, 115, 102, 
    111, 114, 109,   0,  99, 111, 
    108, 111, 114, 115,   0, 102, 
    108, 111,  97, 116,  52,   0, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   8,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  25,   1,   0,   0, 
    115, 104,  97, 100, 111, 119, 
     84,  97, 112, 115,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  12,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  25,   1,   0,   0, 
    108, 105, 103, 104, 116,  80, 
    111, 115,   0, 102, 108, 111, 
     97, 116,  51,   0,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    125,   1,   0,   0,  95, 112, 
     97, 100,  48,   0, 102, 108, 
    111,  97, 116,   0,   0,   0, 
      3,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    174,   1,   0,   0, 108, 105, 
    103, 104, 116,  68, 105, 114, 
      0,  95, 112,  97, 100,  49, 
      0, 112, 111, 105, 110, 116, 
     82,  97, 100, 105, 117, 115, 
      0, 112, 111, 105, 110, 116, 
     83,  99,  97, 108, 101,   0, 
    115, 112, 111, 116,  77, 105, 
    110,   0, 115, 112, 111, 116, 
     77,  97, 120,   0, 109, 111, 
    100, 101,   0, 105, 110, 116, 
      0, 171,   0,   0,   2,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  19,   2, 
      0,   0,  95, 112,  97, 100, 
     50,   0, 171, 171,   0,   0, 
      2,   0,   1,   0,   1,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     19,   2,   0,   0, 193,   0, 
      0,   0, 212,   0,   0,   0, 
      0,   0,   0,   0, 248,   0, 
      0,   0, 212,   0,   0,   0, 
     64,   0,   0,   0,   3,   1, 
      0,   0, 212,   0,   0,   0, 
    128,   0,   0,   0,  18,   1, 
      0,   0,  32,   1,   0,   0, 
    192,   0,   0,   0,  68,   1, 
      0,   0,  80,   1,   0,   0, 
     64,   1,   0,   0, 116,   1, 
      0,   0, 132,   1,   0,   0, 
      0,   2,   0,   0, 168,   1, 
      0,   0, 180,   1,   0,   0, 
     12,   2,   0,   0, 216,   1, 
      0,   0, 132,   1,   0,   0, 
     16,   2,   0,   0, 225,   1, 
      0,   0, 180,   1,   0,   0, 
     28,   2,   0,   0, 231,   1, 
      0,   0, 180,   1,   0,   0, 
     32,   2,   0,   0, 243,   1, 
      0,   0, 180,   1,   0,   0, 
     36,   2,   0,   0, 254,   1, 
      0,   0, 180,   1,   0,   0, 
     40,   2,   0,   0,   6,   2, 
      0,   0, 180,   1,   0,   0, 
     44,   2,   0,   0,  14,   2, 
      0,   0,  24,   2,   0,   0, 
     48,   2,   0,   0,  60,   2, 
      0,   0,  68,   2,   0,   0, 
     64,   2,   0,   0,   5,   0, 
      0,   0,   1,   0, 144,   0, 
      0,   0,  15,   0, 104,   2, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    176,   0,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  54,  46,  51, 
     46,  57,  54,  48,  48,  46, 
     49,  54,  51,  56,  52,   0, 
    171, 171,  73,  83,  71,  78, 
    136,   0,   0,   0,   4,   0, 
      0,   0,   8,   0,   0,   0, 
    104,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,  15,   0,   0, 
    113,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   1,   1,   0,   0, 
    121,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   1,   1,   0,   0, 
    127,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,  15,  15,   0,   0, 
     80,  79,  83,  73,  84,  73, 
     79,  78,   0,  68,  69,  78, 
     83,  73,  84,  89,   0,  80, 
     72,  65,  83,  69,   0,  86, 
     69,  82,  84,  69,  88,   0, 
    171, 171,  79,  83,  71,  53, 
    228,   0,   0,   0,   7,   0, 
      0,   0,   8,   0,   0,   0, 
      0,   0,   0,   0, 204,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,   0,   0, 
      0,   0, 216,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0,   0,   0,   0,   0, 
    216,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,  15,   0,   0,   0, 
      0,   0,   0,   0, 216,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,   0,   0,   0,   0,   0, 
      0,   0, 216,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,  15,   0, 
      0,   0,   0,   0,   0,   0, 
    216,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   5,   0, 
      0,   0,  15,   0,   0,   0, 
      0,   0,   0,   0, 216,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171, 171, 171,  83,  72, 
     69,  88, 236,   7,   0,   0, 
     80,   0,   2,   0, 251,   1, 
      0,   0, 106,   8,   0,   1, 
     53,  24,   0,   0,  18,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     89,   8,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     36,   0,   0,   0,  95,   0, 
      0,   4, 242,  16,  32,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  95,   0,   0,   4, 
     18,  16,  32,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     95,   0,   0,   4,  18,  16, 
     32,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,  95,   0, 
      0,   4, 242,  16,  32,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0, 104,   0,   0,   2, 
      8,   0,   0,   0, 105,   0, 
      0,   4,   0,   0,   0,   0, 
      6,   0,   0,   0,   4,   0, 
      0,   0,  93,   8,   0,   1, 
    143,   0,   0,   3,   0,   0, 
     17,   0,   0,   0,   0,   0, 
     92,  40,   0,   1, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   4,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   5,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   6,   0, 
      0,   0,  94,   0,   0,   2, 
      4,   0,   0,   0,  54,   0, 
      0,   6, 130,  48,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   9,  18,   0,  16,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     34,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
     34,   0,   0,   0,  56,   0, 
      0,   9, 226,   0,  16,   0, 
      0,   0,   0,   0,   6, 137, 
     32,   0,   0,   0,   0,   0, 
     33,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
     34,   0,   0,   0,  50,   0, 
      0,  14, 226,   0,  16,   0, 
      0,   0,   0,   0,  86,  14, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      6,  25,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   1,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  86,   5,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  10,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   8, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  11,   0,   0,   0, 
     56,   0,   0,   9, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     86, 133,  32,   0,   0,   0, 
      0,   0,  33,   0,   0,   0, 
     50,   0,   0,  11, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      6, 128,  32,   0,   0,   0, 
      0,   0,  33,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,  50,   0,   0,  11, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0, 166, 138,  32,   0, 
      0,   0,   0,   0,  33,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  49,   0, 
      0,   8,  34,   0,  16,   0, 
      0,   0,   0,   0,  10,  16, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     50,   0,   0,  16, 114,   0, 
     16,   0,   3,   0,   0,   0, 
      6,  16,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0, 102, 102, 102, 191, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
    205, 204, 204,  61, 205, 204, 
    204,  61,   0,   0, 128,  63, 
      0,   0,   0,   0,  50,   0, 
      0,  16, 114,   0,  16,   0, 
      4,   0,   0,   0,   6,  16, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0, 102, 102, 102, 191, 
    205, 204,  76, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
      0,   0,  32,   0,   0,  11, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      2,   0,   0,   0,   6, 128, 
     32,   0,   0,   0,   0,   0, 
     35,   0,   0,   0,  56,   0, 
      0,   8, 130,   0,  16,   0, 
      3,   0,   0,   0,   1,  64, 
      0,   0, 205, 204,  76,  61, 
     58,  16,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     54,  32,   0,   5, 114,   0, 
     16,   0,   5,   0,   0,   0, 
    246,  15,  16,   0,   3,   0, 
      0,   0,   1,   0,   0,   8, 
    130,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      7,   0,   0,   0,  10,  16, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,  13, 114,   0,  16,   0, 
      6,   0,   0,   0,  70, 130, 
     32,   6,   0,   0,   0,   0, 
     12,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 130,  32,   6,   0,   0, 
      0,   0,  12,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  19, 
    114,   0,  16,   0,   7,   0, 
      0,   0,  70, 130,  32, 134, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  12,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0,   0,   0, 
     50,   0,   0,  12, 114,   0, 
     16,   0,   6,   0,   0,   0, 
     70,   2,  16,   0,   7,   0, 
      0,   0,   2,  64,   0,   0, 
    205, 204, 204,  61, 205, 204, 
    204,  61, 205, 204, 204,  61, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   6,   0,   0,   0, 
     55,   0,   0,   9, 114,   0, 
     16,   0,   3,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  70,   2, 
     16,   0,   4,   0,   0,   0, 
     54,   0,   0,   5,  34,   0, 
     16,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  48,   0,   0,   1, 
     33,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      4,   0,   0,   0,   3,   0, 
      4,   3,  58,   0,  16,   0, 
      3,   0,   0,   0,   0,   0, 
      0,  11,  50,   0,  16,   0, 
      4,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0, 191, 
      0,   0,   0, 191,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     70, 144, 144,   0,  26,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  10,  50,   0, 
     16,   0,   4,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      4,   0,   0,   0,  70,  16, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      7,   0,   0,   0,  86,   5, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      6,   0,  16,   0,   4,   0, 
      0,   0,  70,  14,  16,   0, 
      7,   0,   0,   0,  50,   0, 
      0,  11, 242,   0,  16,   0, 
      4,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 166,  26, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   4,   0,   0,   0, 
     50,   0,   0,  11, 242,   0, 
     16,   0,   4,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
    246,  31,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,   0,   0,   0,   9, 
    130,   0,  16,   0,   3,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0, 128,  63,  26, 144, 
    144, 128,  65,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
    114,   0,  16,   0,   7,   0, 
      0,   0,  70,   2,  16,   0, 
      3,   0,   0,   0,  18,   0, 
      0,   1,  31,   0,   4,   3, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   6, 
    130,  48,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   5,   0, 
      0,   0,  54,   0,   0,   5, 
    114,   0,  16,   0,   7,   0, 
      0,   0,  70,   2,  16,   0, 
      5,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   5, 
    114,   0,  16,   0,   7,   0, 
      0,   0,  70,   2,  16,   0, 
      6,   0,   0,   0,  21,   0, 
      0,   1,  21,   0,   0,   1, 
     54,   0,   0,   6, 130,   0, 
     16,   0,   5,   0,   0,   0, 
     58,  48,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   4,   0, 
      0,   0,  54,   0,   0,   6, 
     18,  32,  16,   0,   1,   0, 
      0,   0,  10, 144, 144,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   5, 
     34,  32,  16,   0,   1,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   8, 194,  32,  16,   0, 
      1,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     54,   0,   0,   5, 242,  32, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    242,  32,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   5, 114,  32,  16,   0, 
      4,   0,   0,   0,  70,   2, 
     16,   0,   7,   0,   0,   0, 
     54,   0,   0,   5, 130,  32, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   5,   0, 
      0,   0,  54,   0,   0,   6, 
    114,  32,  16,   0,   5,   0, 
      0,   0,  70,  18,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  54,   0,   0,   5, 
    130,  32,  16,   0,   5,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   6, 114,  32,  16,   0, 
      6,   0,   0,   0,  70,  18, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      6,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
    117,   0,   0,   3,   0,   0, 
     17,   0,   0,   0,   0,   0, 
     30,   0,   0,   7,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      1,   0,   0,   0,  22,   0, 
      0,   1,  62,   0,   0,   1, 
     83,  84,  65,  84, 148,   0, 
      0,   0,  60,   0,   0,   0, 
      8,   0,   0,   0,   4,   0, 
      0,   0,  11,   0,   0,   0, 
     24,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
      3,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
