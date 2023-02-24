/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
// Generated on: 03.11.2021 09:27:15

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined __GNUC__
#define ALIGN(X) __attribute__((aligned(X)))
#elif defined _MSC_VER
#define ALIGN(X) __declspec(align(X))
#elif defined __TASKING__
#define ALIGN(X) __align(X)
#endif

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

constexpr int kTensorArenaSize = 304;

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext ctx{};
TfLiteTensor tflTensors[14];
TfLiteEvalTensor tflEvalTensors[14];
TfLiteRegistration registrations[OP_LAST];
TfLiteNode tflNodes[5];

const TfArray<2, int> tensor_dimension0 = { 2, { 1,33 } };
const TfArray<1, float> quant0_scale = { 1, { 0.15990845859050751, } };
const TfArray<1, int> quant0_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(8) int32_t tensor_data1[24] = { -3, -26, 0, -10, 9, -116, -56, -132, -130, 287, -40, -173, 1, 153, 139, 415, -56, 0, -1, -3, 228, -56, 28, -49, };
const TfArray<1, int> tensor_dimension1 = { 1, { 24 } };
const TfArray<1, float> quant1_scale = { 1, { 0.0028847993817180395, } };
const TfArray<1, int> quant1_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant1 = { (TfLiteFloatArray*)&quant1_scale, (TfLiteIntArray*)&quant1_zero, 0 };
const ALIGN(8) int32_t tensor_data2[16] = { 24, 174, -99, -165, 29, -62, 282, -12, 21, 129, -23, 273, -1, 75, 201, 93, };
const TfArray<1, int> tensor_dimension2 = { 1, { 16 } };
const TfArray<1, float> quant2_scale = { 1, { 0.0019217287190258503, } };
const TfArray<1, int> quant2_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant2 = { (TfLiteFloatArray*)&quant2_scale, (TfLiteIntArray*)&quant2_zero, 0 };
const ALIGN(8) int32_t tensor_data3[8] = { 8, 76, -94, -11, 135, 206, -20, 172, };
const TfArray<1, int> tensor_dimension3 = { 1, { 8 } };
const TfArray<1, float> quant3_scale = { 1, { 0.002267386531457305, } };
const TfArray<1, int> quant3_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant3 = { (TfLiteFloatArray*)&quant3_scale, (TfLiteIntArray*)&quant3_zero, 0 };
const ALIGN(8) int32_t tensor_data4[8] = { -10, 3, -131, -55, -38, 100, 48, -5, };
const TfArray<1, int> tensor_dimension4 = { 1, { 8 } };
const TfArray<1, float> quant4_scale = { 1, { 0.0076197455637156963, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(8) int8_t tensor_data5[24*33] = { 
  -14, 10, 6, -11, -1, -15, -7, 7, 16, 0, -12, -4, -18, -18, 12, 12, 3, -2, -4, -8, -11, -8, -16, 5, 17, -11, -9, -8, 15, 4, -9, 9, -15, 
  4, -24, 2, 23, 26, 5, 10, 15, 10, -46, 95, -14, 6, 5, 3, -2, 2, -2, -2, -11, -36, -12, -28, -10, -8, 7, 30, 0, 38, -34, -54, -52, 44, 
  0, 16, -17, -8, 11, -17, -4, 2, -7, -15, -13, -13, -2, -3, -7, 15, -6, -10, 7, -5, -8, 0, -13, -2, 3, -12, -5, -17, 12, 8, 4, 12, -11, 
  -19, 16, -2, 5, 2, -12, -17, 13, 13, -5, 2, -9, -12, -15, 3, 15, -5, 9, -9, 15, -4, -17, -5, 5, -17, 0, 15, -12, 10, 4, 4, 3, 14, 
  14, 12, 5, 8, 16, 0, 5, 9, 52, 22, 94, -10, 11, 7, -2, 1, 0, -25, -12, -16, -15, 2, -38, -18, -32, -2, 42, 1, 40, -7, 0, 21, 55, 
  17, 8, -11, -12, 26, -5, -12, 4, 45, 49, 78, -5, -11, -13, -4, 21, -2, -17, -3, 3, 43, -1, 28, 13, 8, -2, 51, -1, 22, 45, 59, 91, 93, 
  -8, -22, 25, 9, -5, 3, 4, 5, 5, -16, -71, 12, -9, 15, -5, -19, 1, -13, -23, -17, -38, -31, -25, -16, -12, 1, -49, 5, -32, 0, -38, -53, -97, 
  -8, -16, -14, 10, 21, 1, 3, -1, 18, -25, 107, -11, 4, 5, 1, 15, 8, 27, 23, 9, 12, 25, 14, -4, -6, -6, 62, -3, 50, 9, 5, 30, 126, 
  6, 0, 5, -5, 9, -2, -11, 1, 46, 16, 40, 14, -28, 14, -8, 16, -3, -4, 26, 20, -1, 4, -17, -22, -17, -8, 20, -7, 21, -17, 2, 6, 19, 
  3, 19, -14, 13, 18, 4, 9, -8, 10, -5, -2, -5, 8, -2, -1, 1, 4, -30, -8, -11, 5, 5, -57, -20, -38, -24, 9, 2, -17, -36, -49, -53, -56, 
  -2, -19, 25, 3, 21, 1, 18, 13, -3, 14, 48, -11, -6, -26, 1, 1, -14, 10, -31, -26, 37, 32, 16, -7, -6, 22, 0, 16, -14, -10, -9, 32, 53, 
  15, -4, -2, 1, 32, -4, -18, 10, 35, 15, 117, -11, -7, -12, -1, 15, 1, -7, 22, -2, 19, 3, 5, -9, 6, -12, 56, 12, 34, 19, 49, 65, 127, 
  3, 43, -1, 7, 13, -1, 4, -14, -13, 43, -68, -14, 35, -8, -4, -26, 0, -33, -20, -3, -18, -11, 25, 42, 15, 6, -9, 5, -27, 13, 16, 32, -14, 
  -10, 25, -17, 5, 10, 8, 18, -6, -54, -2, -20, -6, 15, -9, 6, 14, 5, -13, -1, 1, -3, -3, 6, 35, 6, -9, 16, -1, -10, 11, 9, 35, -11, 
  -6, -11, 11, -2, 3, -2, -7, 6, -11, -11, 45, 10, -14, 12, 4, -6, 5, 12, 32, -3, -30, -18, -43, -18, -47, -4, 22, -2, 5, -29, -41, -49, 5, 
  -16, -3, 3, -25, 13, -12, -16, 15, 8, 14, -8, -12, -19, -7, -1, 2, -4, -13, -20, 2, -9, 15, -11, -5, 5, -15, -11, -15, 2, -16, -6, -8, 2, 
  -8, -28, 18, 5, 7, -1, 0, 11, -21, -46, 30, 10, -17, 16, 5, -31, 5, -29, 4, -24, -47, -55, -8, -3, -13, -4, -11, 1, 7, -25, -56, -60, -30, 
  -8, 0, -3, -15, -4, 3, -14, -15, 1, 16, 4, -10, 3, 5, -9, -9, -1, -17, -1, -7, 16, 4, -7, 15, -8, 10, -17, 16, -3, 9, 16, 12, -10, 
  -20, -10, -1, 11, -9, 2, 3, 3, -46, -55, -58, 12, 11, -5, 3, -16, 6, -8, 0, -7, -38, -19, 20, 21, 26, 13, -56, -6, -8, -13, -14, -60, -84, 
  -1, -6, 6, 19, 5, 1, 10, -10, -14, -29, -44, 2, 23, 7, 10, -12, -6, -24, -14, -27, -34, -36, -9, -2, -4, -6, -33, -32, -9, -23, -27, -83, -72, 
  -14, 28, -16, 14, 1, -5, 2, -19, -2, 29, -76, -13, 14, 4, 1, 13, 3, 2, 7, 33, 17, 27, 18, 48, 26, -20, -7, 0, -33, 11, 56, 30, -49, 
  6, -5, 15, -6, -10, 0, -1, 3, 5, 16, -58, 9, -12, -13, 0, 5, 1, -24, -3, -22, -12, -9, 23, 33, 44, 12, -14, 2, 15, 8, 35, 41, -12, 
  -23, -26, -15, 7, 6, 0, -8, 9, -35, -64, 65, 23, -21, 1, 11, -11, 1, 25, 10, 23, 5, 20, 19, -9, 8, 8, -3, -2, 30, -2, -17, -47, 56, 
  -1, 12, 0, -6, -11, 2, 6, 8, 0, 62, -72, -7, 11, -1, -8, 8, 3, -24, -7, -6, 40, -6, 52, 27, 20, 8, -43, -5, -17, 37, 46, 65, -53, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 24,33 } };
const TfArray<1, float> quant5_scale = { 1, { 0.018040318042039871, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(8) int8_t tensor_data6[16*24] = { 
  -15, -5, -12, 19, -18, -50, 36, -43, 7, -17, -60, -25, -31, -11, 10, -19, 26, -14, 30, 23, 5, 17, 8, 0, 
  -15, 28, -19, -15, 29, -55, 37, -17, -9, 59, -60, -20, -27, 9, 23, -33, 13, 20, 7, 45, 16, -6, -31, -9, 
  -18, 26, -17, -13, 44, 52, -29, 27, 57, -7, -34, 52, -14, -46, 15, -12, 6, -18, -21, -24, 14, 11, 33, 9, 
  -16, 22, 2, 0, 21, 36, -26, 49, 1, 30, -7, 17, 0, 4, 44, -21, 11, -21, -25, 7, -25, -2, 11, -28, 
  3, 12, 18, -2, -6, -24, 5, 0, -17, -60, 25, -6, -21, -24, 18, 2, 51, -19, 47, 16, -7, 30, 22, 34, 
  14, 2, -22, 12, 15, 83, -16, 41, -14, -10, 29, 23, 56, 30, -45, -23, -10, 1, 6, 3, 11, 9, -8, 21, 
  18, -28, 11, 18, -27, -8, -24, 18, 9, 13, -1, -12, -22, 11, 9, 75, -18, 18, -33, -47, 14, -38, 4, -38, 
  -12, -26, 18, -2, -22, 26, -1, 23, 16, -11, -29, 10, 51, 38, -3, -41, -39, -20, 0, 10, 52, 7, -3, 29, 
  -16, -2, 19, -8, -33, -18, -15, 36, 5, -38, -24, 11, 6, -1, 38, 65, 29, -18, 28, -12, 3, -5, 68, 2, 
  -6, -3, 6, -2, 44, -25, -6, -15, -7, 80, -12, -34, 16, 24, 40, 65, -12, -1, 7, 4, 0, -25, -23, -33, 
  -1, -23, 15, 0, -37, -54, -23, 14, 15, 19, -5, 1, 9, 15, 33, -3, -13, 0, -20, -37, 9, -36, 22, -40, 
  3, -17, -3, 11, 4, -44, 28, 4, -3, 48, 3, -6, -18, 1, 25, 127, 13, 6, -49, 13, 21, -25, 6, -29, 
  16, 16, -23, -7, 69, 26, 28, -9, 7, 25, 28, 22, -9, -37, 0, -15, 14, 9, -22, -9, -8, 17, -15, 22, 
  -4, 4, -16, 18, -44, -22, 1, -35, -46, -13, 30, -16, 29, 23, -51, -36, 2, -22, 9, 23, 17, 15, 22, 4, 
  1, -15, 14, 12, -14, 20, -11, -19, 3, 53, -43, 3, 27, 36, -71, 22, -40, 19, 22, -6, 24, 7, -13, 6, 
  19, 1, -5, 17, -49, -37, -31, -19, -46, 27, -13, -43, 30, 39, -16, -47, -4, -16, 23, 8, 17, 3, -9, 5, 
};
const TfArray<2, int> tensor_dimension6 = { 2, { 16,24 } };
const TfArray<1, float> quant6_scale = { 1, { 0.01620437391102314, } };
const TfArray<1, int> quant6_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(8) int8_t tensor_data7[8*16] = { 
  -3, 5, -4, -32, 59, 91, -85, 69, 4, -9, -60, -67, 47, 125, 116, 99, 
  65, 82, 38, 58, 45, -60, -64, -26, 11, 26, -47, 30, 69, -109, -103, -75, 
  -37, -50, 68, 73, 39, 101, 10, 90, 82, -69, 67, -12, 18, 34, -35, -32, 
  -39, 68, -15, -8, -21, -32, 3, -36, -55, 33, 8, -3, 45, 11, 17, -19, 
  -23, 20, 19, 21, 21, 4, 113, 1, -47, 97, 0, 106, 40, -38, 80, -34, 
  40, 87, 6, -23, 38, -48, 125, 32, 73, 71, 65, 93, -41, 42, 39, 67, 
  -112, 46, 25, 13, -86, 24, -53, 67, -83, 77, -8, 39, -24, 8, 37, 38, 
  65, 19, 21, -82, 63, -41, -27, 22, 5, -127, 16, -36, 43, 39, -23, -55, 
};
const TfArray<2, int> tensor_dimension7 = { 2, { 8,16 } };
const TfArray<1, float> quant7_scale = { 1, { 0.0092092584818601608, } };
const TfArray<1, int> quant7_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const ALIGN(8) int8_t tensor_data8[8*8] = { 
  24, -54, 5, 12, 35, -76, 9, 26, 
  -70, 44, -92, 46, 34, -14, -35, -64, 
  -79, -53, 29, -44, 4, 33, -24, -38, 
  16, 15, 38, 3, -27, -68, -58, -26, 
  31, -43, -85, 29, -33, 10, 82, -88, 
  -73, -127, -104, 9, 46, 47, -22, -18, 
  -33, 3, -38, -27, -27, 3, -6, 71, 
  61, -70, -27, -70, -79, 27, -52, -41, 
};
const TfArray<2, int> tensor_dimension8 = { 2, { 8,8 } };
const TfArray<1, float> quant8_scale = { 1, { 0.013639863580465317, } };
const TfArray<1, int> quant8_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<2, int> tensor_dimension9 = { 2, { 1,24 } };
const TfArray<1, float> quant9_scale = { 1, { 0.11859320849180222, } };
const TfArray<1, int> quant9_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<2, int> tensor_dimension10 = { 2, { 1,16 } };
const TfArray<1, float> quant10_scale = { 1, { 0.24620729684829712, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfArray<2, int> tensor_dimension11 = { 2, { 1,8 } };
const TfArray<1, float> quant11_scale = { 1, { 0.55863797664642334, } };
const TfArray<1, int> quant11_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<2, int> tensor_dimension12 = { 2, { 1,8 } };
const TfArray<1, float> quant12_scale = { 1, { 1.0234571695327759, } };
const TfArray<1, int> quant12_zero = { 1, { 48 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<2, int> tensor_dimension13 = { 2, { 1,8 } };
const TfArray<1, float> quant13_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant13_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfLiteFullyConnectedParams opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs0 = { 3, { 0,5,1 } };
const TfArray<1, int> outputs0 = { 1, { 9 } };
const TfLiteFullyConnectedParams opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs1 = { 3, { 9,6,2 } };
const TfArray<1, int> outputs1 = { 1, { 10 } };
const TfLiteFullyConnectedParams opdata2 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs2 = { 3, { 10,7,3 } };
const TfArray<1, int> outputs2 = { 1, { 11 } };
const TfLiteFullyConnectedParams opdata3 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs3 = { 3, { 11,8,4 } };
const TfArray<1, int> outputs3 = { 1, { 12 } };
const TfLiteSoftmaxParams opdata4 = { 1 };
const TfArray<1, int> inputs4 = { 1, { 12 } };
const TfArray<1, int> outputs4 = { 1, { 13 } };
const TensorInfo_t tensorData[] = {
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension0, 33, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant0))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data1, (TfLiteIntArray*)&tensor_dimension1, 96, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant1))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data2, (TfLiteIntArray*)&tensor_dimension2, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant2))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data3, (TfLiteIntArray*)&tensor_dimension3, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant3))}, },
  { kTfLiteMmapRo, kTfLiteInt32, (void*)tensor_data4, (TfLiteIntArray*)&tensor_dimension4, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant4))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data5, (TfLiteIntArray*)&tensor_dimension5, 792, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant5))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data6, (TfLiteIntArray*)&tensor_dimension6, 384, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant6))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data7, (TfLiteIntArray*)&tensor_dimension7, 128, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant7))}, },
  { kTfLiteMmapRo, kTfLiteInt8, (void*)tensor_data8, (TfLiteIntArray*)&tensor_dimension8, 64, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant8))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 48, (TfLiteIntArray*)&tensor_dimension9, 24, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant9))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 16, (TfLiteIntArray*)&tensor_dimension10, 16, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant10))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension11, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant11))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 16, (TfLiteIntArray*)&tensor_dimension12, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant12))}, },
  { kTfLiteArenaRw, kTfLiteInt8, tensor_arena + 0, (TfLiteIntArray*)&tensor_dimension13, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&quant13))}, },
};const NodeInfo_t nodeData[] = {
  { (TfLiteIntArray*)&inputs0, (TfLiteIntArray*)&outputs0, const_cast<void*>(static_cast<const void*>(&opdata0)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs1, (TfLiteIntArray*)&outputs1, const_cast<void*>(static_cast<const void*>(&opdata1)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs2, (TfLiteIntArray*)&outputs2, const_cast<void*>(static_cast<const void*>(&opdata2)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs3, (TfLiteIntArray*)&outputs3, const_cast<void*>(static_cast<const void*>(&opdata3)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&inputs4, (TfLiteIntArray*)&outputs4, const_cast<void*>(static_cast<const void*>(&opdata4)), OP_SOFTMAX, },
};
static std::vector<void*> overflow_buffers;
static void * AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  if (current_location - bytes < tensor_boundary) {
    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers.push_back(ptr);
    return ptr;
  }

  current_location -= bytes;

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}
typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;
static std::vector<scratch_buffer_t> scratch_buffers;

static TfLiteStatus RequestScratchBufferInArena(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBuffer(ctx, b.bytes);
  if (!b.ptr) {
    return kTfLiteError;
  }

  scratch_buffers.push_back(b);

  *buffer_idx = scratch_buffers.size() - 1;

  return kTfLiteOk;
}

static void* GetScratchBuffer(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > static_cast<int>(scratch_buffers.size()) - 1) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static TfLiteTensor* GetTensor(const struct TfLiteContext* context,
                               int tensor_idx) {
  return &tflTensors[tensor_idx];
}

static TfLiteEvalTensor* GetEvalTensor(const struct TfLiteContext* context,
                                       int tensor_idx) {
  return &tflEvalTensors[tensor_idx];
}

} // namespace

TfLiteStatus trained_model_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;
  ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArena;
  ctx.GetScratchBuffer = &GetScratchBuffer;
  ctx.GetTensor = &GetTensor;
  ctx.GetEvalTensor = &GetEvalTensor;
  ctx.tensors = tflTensors;
  ctx.tensors_size = 14;
  for(size_t i = 0; i < 14; ++i) {
    tflTensors[i].type = tensorData[i].type;
    tflEvalTensors[i].type = tensorData[i].type;
    tflTensors[i].is_variable = 0;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    tflTensors[i].allocation_type = tensorData[i].allocation_type;
#else
    tflTensors[i].allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
    tflTensors[i].bytes = tensorData[i].bytes;
    tflTensors[i].dims = tensorData[i].dims;
    tflEvalTensors[i].dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
    if(tflTensors[i].allocation_type == kTfLiteArenaRw){
      uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

     tflTensors[i].data.data =  start;
     tflEvalTensors[i].data.data =  start;
    }
    else{
       tflTensors[i].data.data = tensorData[i].data;
       tflEvalTensors[i].data.data = tensorData[i].data;
    }
#else
    tflTensors[i].data.data = tensorData[i].data;
    tflEvalTensors[i].data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
    tflTensors[i].quantization = tensorData[i].quantization;
    if (tflTensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
      tflTensors[i].params.scale = quant->scale->data[0];
      tflTensors[i].params.zero_point = quant->zero_point->data[0];
    }
    if (tflTensors[i].allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tflTensors[i].data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }
  if (tensor_boundary > current_location /* end of arena size */) {
    printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for(size_t i = 0; i < 5; ++i) {
    tflNodes[i].inputs = nodeData[i].inputs;
    tflNodes[i].outputs = nodeData[i].outputs;
    tflNodes[i].builtin_data = nodeData[i].builtin_data;
    tflNodes[i].custom_initial_data = nullptr;
    tflNodes[i].custom_initial_data_size = 0;
    if (registrations[nodeData[i].used_op_index].init) {
      tflNodes[i].user_data = registrations[nodeData[i].used_op_index].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 5; ++i) {
    if (registrations[nodeData[i].used_op_index].prepare) {
      TfLiteStatus status = registrations[nodeData[i].used_op_index].prepare(&ctx, &tflNodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
TfLiteTensor* trained_model_input(int index) {
  return &ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  13, 
};
TfLiteTensor* trained_model_output(int index) {
  return &ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus trained_model_invoke() {
  for(size_t i = 0; i < 5; ++i) {
    TfLiteStatus status = registrations[nodeData[i].used_op_index].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus trained_model_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif
  scratch_buffers.clear();
  for (size_t ix = 0; ix < overflow_buffers.size(); ix++) {
    free(overflow_buffers[ix]);
  }
  overflow_buffers.clear();
  return kTfLiteOk;
}
