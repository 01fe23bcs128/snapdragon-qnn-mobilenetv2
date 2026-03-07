/* COPYRIGHT HEADER GOES HERE: No CopyRight Header String Passed During Model Conversion */

/* Command Line used:
qnn-onnx-converter; act_bitwidth=8; act_quantizer=tf; act_quantizer_calibration=min-max; act_quantizer_schema=asymmetric; adjust_nms_features_dims=True; algorithms=[]; align_matmul_ranks=True; apply_masked_softmax=uncompressed; arch_checker=False; backend=None; batch=None; bias_bitwidth=8; calc_static_encodings=False; converter_op_package_lib=; copyright_file=None; custom_io=; custom_op_config_paths=None; debug=-1; defer_loading=False; define_symbol=None; disable_batchnorm_folding=False; disable_defer_loading=False; disable_node_validation=False; disable_qnn_op_config_validation=False; disable_relu_squashing=False; dry_run=None; dumpIR=False; dump_custom_io_config_template=; dump_encoding_json=False; dump_inferred_model=False; dump_ir=; dump_ir_optimizer_config_template=False; dump_optimization_pass_mode_config=False; dump_pass_trace_info=False; dump_qairt_io_config_yaml=; dump_qairt_quantizer_command=None; dump_value_info=False; enable_framework_trace=False; enable_match_gathernd=False; enable_match_topk=False; enable_per_row_quantized_bias=False; exclude_named_tensors=False; expand_gru_op_structure=True; expand_lstm_op_structure=False; expand_sparse_op_structure=False; export_format=cpp; extract_color_transform=True; float_bias_bitwidth=0; float_bias_bw=0; float_bitwidth=32; float_bw=32; float_fallback=False; force_prune_cast_ops=False; handle_gather_negative_indices=True; ignore_encodings=False; include_data_invariant_ops=False; inject_cast_for_gather=True; input_dim=[['input', '1,3,224,224']]; input_dtype=[]; input_encoding=[]; input_layout=[]; input_list=None; input_type=[]; ir_optimizer_config=; keep_disconnected_nodes=False; keep_int64_inputs=False; keep_quant_nodes=False; keep_weights_quantized=False; match_caffe_ssd_to_tf=True; model_version=None; multi_time_steps_gru=False; multi_time_steps_lstm=False; no_simplification=False; op_package_lib=; optimization_pass_mode=ir_optimizer_mainline; optimization_pass_mode_config=; out_names=['output']; overwrite_model_prefix=False; pack_4_bit_weights=False; package_name=None; packed_masked_softmax_inputs=[]; packed_max_seq=1; param_quantizer=None; param_quantizer_calibration=min-max; param_quantizer_schema=asymmetric; percentile_calibration_value=99.99; perform_axes_to_spatial_first_order=True; perform_layout_transformation=False; prepare_inputs_as_params=False; preprocess_roi_pool_inputs=True; preserve_io=[]; preserve_onnx_output_order=False; quantization_overrides=; quantizer_log=None; quantizer_log_level=LogLevel.NONE; restrict_quantization_steps=[]; squash_box_decoder=True; unroll_gru_time_steps=True; unroll_lstm_time_steps=True; use_aimet_quantizer=False; use_convert_quantization_nodes=False; use_dynamic_16_bit_weights=False; use_native_dtype=False; use_native_input_files=False; use_native_output_files=False; use_per_channel_quantization=False; use_per_row_quantization=False; use_quantize_v2=False; validate_models=False; weights_bitwidth=8
*/

#include "QnnOpDef.h"
#include "QnnModel.hpp"

// Flag to determine if Backend should do node validation for each opNode added
#define DO_GRAPH_NODE_VALIDATIONS 1

using namespace qnn_wrapper_api;
const __attribute__((visibility("default"))) char* QNN_SDK_VERSION = "qaisw-v2.43.0.260127150333_193827";
extern "C" {
static ModelError_t addTensor_input(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_input[] = {1, 224, 224, 3};
  VALIDATE(model.addTensor("input", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "input",
                                 .type= QNN_TENSOR_TYPE_APP_WRITE,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_input,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=nullptr,
                                                .dataSize=0}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_679(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_679[] = {3, 3, 3, 32};
  VALIDATE(model.addTensor("onnx__Conv_679", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_679",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_679,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_679),
                                                .dataSize=BINLEN(onnx__Conv_679)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_680(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_680[] = {32};
  VALIDATE(model.addTensor("onnx__Conv_680", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_680",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_680,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_680),
                                                .dataSize=BINLEN(onnx__Conv_680)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__conv_stem_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _conv_stem_Conv */
  uint32_t dimensions__conv_stem_Conv_dilation[] = {2};
  uint32_t _conv_stem_Conv_dilation[] = {1, 1};
  uint32_t dimensions__conv_stem_Conv_pad_amount[] = {2, 2};
  uint32_t _conv_stem_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__conv_stem_Conv_stride[] = {2};
  uint32_t _conv_stem_Conv_stride[] = {2, 2};
  Qnn_Param_t params__conv_stem_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_stem_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__conv_stem_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_conv_stem_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_stem_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__conv_stem_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_conv_stem_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_stem_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__conv_stem_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_conv_stem_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__conv_stem_Conv[] = {
    "input",
    "onnx__Conv_679",
    "onnx__Conv_680"
  };
  uint32_t dimensions__conv_stem_Conv_output_0[] = {1, 112, 112, 32};
  Qnn_Tensor_t outputs__conv_stem_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_stem_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__conv_stem_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_conv_stem_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__conv_stem_Conv, // Node Params
                         5, // Num Node Params
                         inputs__conv_stem_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__conv_stem_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__bn1_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _bn1_act_Relu */
  Qnn_Param_t params__bn1_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__bn1_act_Relu[] = {
    "_conv_stem_Conv_output_0"
  };
  uint32_t dimensions__bn1_act_Relu_output_0[] = {1, 112, 112, 32};
  Qnn_Tensor_t outputs__bn1_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_bn1_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__bn1_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_bn1_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__bn1_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__bn1_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__bn1_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_682(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_682[] = {3, 3, 32, 128};
  VALIDATE(model.addTensor("onnx__Conv_682", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_682",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_682,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_682),
                                                .dataSize=BINLEN(onnx__Conv_682)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_683(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_683[] = {128};
  VALIDATE(model.addTensor("onnx__Conv_683", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_683",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_683,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_683),
                                                .dataSize=BINLEN(onnx__Conv_683)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_0_blocks_0_0_conv_exp_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_0_blocks_0_0_conv_exp_Conv */
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_0_blocks_0_0_conv_exp_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_0_blocks_0_0_conv_exp_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_stride[] = {2};
  uint32_t _blocks_blocks_0_blocks_0_0_conv_exp_Conv_stride[] = {2, 2};
  Qnn_Param_t params__blocks_blocks_0_blocks_0_0_conv_exp_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_exp_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_0_blocks_0_0_conv_exp_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_exp_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_0_blocks_0_0_conv_exp_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_exp_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_0_blocks_0_0_conv_exp_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_0_blocks_0_0_conv_exp_Conv[] = {
    "_bn1_act_Relu_output_0",
    "onnx__Conv_682",
    "onnx__Conv_683"
  };
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_output_0[] = {1, 56, 56, 128};
  Qnn_Tensor_t outputs__blocks_blocks_0_blocks_0_0_conv_exp_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_exp_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_exp_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_0_blocks_0_0_conv_exp_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_0_blocks_0_0_conv_exp_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_0_blocks_0_0_conv_exp_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_0_blocks_0_0_conv_exp_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_0_blocks_0_0_bn1_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_0_blocks_0_0_bn1_act_Relu */
  Qnn_Param_t params__blocks_blocks_0_blocks_0_0_bn1_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_0_blocks_0_0_bn1_act_Relu[] = {
    "_blocks_blocks_0_blocks_0_0_conv_exp_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_bn1_act_Relu_output_0[] = {1, 56, 56, 128};
  Qnn_Tensor_t outputs__blocks_blocks_0_blocks_0_0_bn1_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_bn1_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_bn1_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_0_blocks_0_0_bn1_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_0_blocks_0_0_bn1_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_0_blocks_0_0_bn1_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_0_blocks_0_0_bn1_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_685(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_685[] = {1, 1, 128, 48};
  VALIDATE(model.addTensor("onnx__Conv_685", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_685",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_685,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_685),
                                                .dataSize=BINLEN(onnx__Conv_685)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_686(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_686[] = {48};
  VALIDATE(model.addTensor("onnx__Conv_686", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_686",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_686,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_686),
                                                .dataSize=BINLEN(onnx__Conv_686)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_0_blocks_0_0_conv_pwl_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_0_blocks_0_0_conv_pwl_Conv */
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_0_blocks_0_0_conv_pwl_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_0_blocks_0_0_conv_pwl_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_stride[] = {2};
  uint32_t _blocks_blocks_0_blocks_0_0_conv_pwl_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_0_blocks_0_0_conv_pwl_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_0_blocks_0_0_conv_pwl_Conv[] = {
    "_blocks_blocks_0_blocks_0_0_bn1_act_Relu_output_0",
    "onnx__Conv_685",
    "onnx__Conv_686"
  };
  uint32_t dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_output_0[] = {1, 56, 56, 48};
  Qnn_Tensor_t outputs__blocks_blocks_0_blocks_0_0_conv_pwl_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_0_blocks_0_0_conv_pwl_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_0_blocks_0_0_conv_pwl_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_0_blocks_0_0_conv_pwl_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_0_blocks_0_0_conv_pwl_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_0_blocks_0_0_conv_pwl_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_688(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_688[] = {3, 3, 1, 48};
  VALIDATE(model.addTensor("onnx__Conv_688", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_688",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_688,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_688),
                                                .dataSize=BINLEN(onnx__Conv_688)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_689(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_689[] = {48};
  VALIDATE(model.addTensor("onnx__Conv_689", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_689",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_689,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_689),
                                                .dataSize=BINLEN(onnx__Conv_689)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_0_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv[] = {
    "_blocks_blocks_0_blocks_0_0_conv_pwl_Conv_output_0",
    "onnx__Conv_688",
    "onnx__Conv_689"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_output_0[] = {1, 56, 56, 48};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_691(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_691[] = {1, 1, 48, 192};
  VALIDATE(model.addTensor("onnx__Conv_691", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_691",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_691,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_691),
                                                .dataSize=BINLEN(onnx__Conv_691)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_692(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_692[] = {192};
  VALIDATE(model.addTensor("onnx__Conv_692", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_692",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_692,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_692),
                                                .dataSize=BINLEN(onnx__Conv_692)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_0_dw_start_conv_Conv_output_0",
    "onnx__Conv_691",
    "onnx__Conv_692"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_output_0[] = {1, 56, 56, 192};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu_output_0[] = {1, 56, 56, 192};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_694(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_694[] = {5, 5, 1, 192};
  VALIDATE(model.addTensor("onnx__Conv_694", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_694",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_694,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_694),
                                                .dataSize=BINLEN(onnx__Conv_694)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_695(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_695[] = {192};
  VALIDATE(model.addTensor("onnx__Conv_695", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_695",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_695,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_695),
                                                .dataSize=BINLEN(onnx__Conv_695)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_stride[] = {2, 2};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_694",
    "onnx__Conv_695"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_output_0[] = {1, 28, 28, 192};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu_output_0[] = {1, 28, 28, 192};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_697(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_697[] = {1, 1, 192, 80};
  VALIDATE(model.addTensor("onnx__Conv_697", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_697",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_697,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_697),
                                                .dataSize=BINLEN(onnx__Conv_697)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_698(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_698[] = {80};
  VALIDATE(model.addTensor("onnx__Conv_698", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_698",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_698,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_698),
                                                .dataSize=BINLEN(onnx__Conv_698)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_697",
    "onnx__Conv_698"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_output_0[] = {1, 28, 28, 80};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_700(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_700[] = {3, 3, 1, 80};
  VALIDATE(model.addTensor("onnx__Conv_700", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_700",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_700,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_700),
                                                .dataSize=BINLEN(onnx__Conv_700)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_701(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_701[] = {80};
  VALIDATE(model.addTensor("onnx__Conv_701", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_701",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_701,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_701),
                                                .dataSize=BINLEN(onnx__Conv_701)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_output_0",
    "onnx__Conv_700",
    "onnx__Conv_701"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_output_0[] = {1, 28, 28, 80};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_703(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_703[] = {1, 1, 80, 160};
  VALIDATE(model.addTensor("onnx__Conv_703", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_703",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_703,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_703),
                                                .dataSize=BINLEN(onnx__Conv_703)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_704(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_704[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_704", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_704",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_704,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_704),
                                                .dataSize=BINLEN(onnx__Conv_704)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_1_dw_start_conv_Conv_output_0",
    "onnx__Conv_703",
    "onnx__Conv_704"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_output_0[] = {1, 28, 28, 160};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu_output_0[] = {1, 28, 28, 160};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_706(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_706[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_706", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_706",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_706,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_706),
                                                .dataSize=BINLEN(onnx__Conv_706)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_707(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_707[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_707", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_707",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_707,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_707),
                                                .dataSize=BINLEN(onnx__Conv_707)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_706",
    "onnx__Conv_707"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_output_0[] = {1, 28, 28, 160};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu_output_0[] = {1, 28, 28, 160};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_709(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_709[] = {1, 1, 160, 80};
  VALIDATE(model.addTensor("onnx__Conv_709", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_709",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_709,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_709),
                                                .dataSize=BINLEN(onnx__Conv_709)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_710(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_710[] = {80};
  VALIDATE(model.addTensor("onnx__Conv_710", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_710",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_710,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_710),
                                                .dataSize=BINLEN(onnx__Conv_710)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_709",
    "onnx__Conv_710"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_output_0[] = {1, 28, 28, 80};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_1_blocks_1_1_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_1_blocks_1_1_Add */
  Qnn_Param_t params__blocks_blocks_1_blocks_1_1_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_1_blocks_1_1_Add[] = {
    "_blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_1_blocks_1_1_Add_output_0[] = {1, 28, 28, 80};
  Qnn_Tensor_t outputs__blocks_blocks_1_blocks_1_1_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_1_blocks_1_1_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_1_blocks_1_1_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_1_blocks_1_1_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_1_blocks_1_1_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_1_blocks_1_1_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_1_blocks_1_1_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_712(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_712[] = {3, 3, 1, 80};
  VALIDATE(model.addTensor("onnx__Conv_712", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_712",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_712,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_712),
                                                .dataSize=BINLEN(onnx__Conv_712)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_713(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_713[] = {80};
  VALIDATE(model.addTensor("onnx__Conv_713", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_713",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_713,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_713),
                                                .dataSize=BINLEN(onnx__Conv_713)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_0_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv[] = {
    "_blocks_blocks_1_blocks_1_1_Add_output_0",
    "onnx__Conv_712",
    "onnx__Conv_713"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_output_0[] = {1, 28, 28, 80};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_715(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_715[] = {1, 1, 80, 480};
  VALIDATE(model.addTensor("onnx__Conv_715", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_715",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_715,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_715),
                                                .dataSize=BINLEN(onnx__Conv_715)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_716(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_716[] = {480};
  VALIDATE(model.addTensor("onnx__Conv_716", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_716",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_716,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_716),
                                                .dataSize=BINLEN(onnx__Conv_716)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_0_dw_start_conv_Conv_output_0",
    "onnx__Conv_715",
    "onnx__Conv_716"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_output_0[] = {1, 28, 28, 480};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu_output_0[] = {1, 28, 28, 480};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_718(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_718[] = {5, 5, 1, 480};
  VALIDATE(model.addTensor("onnx__Conv_718", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_718",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_718,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_718),
                                                .dataSize=BINLEN(onnx__Conv_718)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_719(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_719[] = {480};
  VALIDATE(model.addTensor("onnx__Conv_719", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_719",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_719,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_719),
                                                .dataSize=BINLEN(onnx__Conv_719)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_stride[] = {2, 2};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_718",
    "onnx__Conv_719"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_output_0[] = {1, 14, 14, 480};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu_output_0[] = {1, 14, 14, 480};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_721(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_721[] = {1, 1, 480, 160};
  VALIDATE(model.addTensor("onnx__Conv_721", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_721",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_721,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_721),
                                                .dataSize=BINLEN(onnx__Conv_721)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_722(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_722[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_722", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_722",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_722,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_722),
                                                .dataSize=BINLEN(onnx__Conv_722)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_721",
    "onnx__Conv_722"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_724(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_724[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_724", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_724",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_724,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_724),
                                                .dataSize=BINLEN(onnx__Conv_724)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_725(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_725[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_725", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_725",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_725,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_725),
                                                .dataSize=BINLEN(onnx__Conv_725)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_output_0",
    "onnx__Conv_724",
    "onnx__Conv_725"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_727(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_727[] = {1, 1, 160, 640};
  VALIDATE(model.addTensor("onnx__Conv_727", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_727",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_727,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_727),
                                                .dataSize=BINLEN(onnx__Conv_727)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_728(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_728[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_728", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_728",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_728,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_728),
                                                .dataSize=BINLEN(onnx__Conv_728)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_1_dw_start_conv_Conv_output_0",
    "onnx__Conv_727",
    "onnx__Conv_728"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_730(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_730[] = {3, 3, 1, 640};
  VALIDATE(model.addTensor("onnx__Conv_730", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_730",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_730,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_730),
                                                .dataSize=BINLEN(onnx__Conv_730)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_731(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_731[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_731", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_731",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_731,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_731),
                                                .dataSize=BINLEN(onnx__Conv_731)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_730",
    "onnx__Conv_731"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_733(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_733[] = {1, 1, 640, 160};
  VALIDATE(model.addTensor("onnx__Conv_733", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_733",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_733,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_733),
                                                .dataSize=BINLEN(onnx__Conv_733)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_734(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_734[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_734", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_734",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_734,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_734),
                                                .dataSize=BINLEN(onnx__Conv_734)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_733",
    "onnx__Conv_734"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_1_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_1_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_1_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_1_Add[] = {
    "_blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_1_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_1_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_1_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_1_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_1_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_1_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_1_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_1_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_736(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_736[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_736", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_736",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_736,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_736),
                                                .dataSize=BINLEN(onnx__Conv_736)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_737(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_737[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_737", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_737",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_737,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_737),
                                                .dataSize=BINLEN(onnx__Conv_737)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_1_Add_output_0",
    "onnx__Conv_736",
    "onnx__Conv_737"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_739(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_739[] = {1, 1, 160, 640};
  VALIDATE(model.addTensor("onnx__Conv_739", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_739",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_739,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_739),
                                                .dataSize=BINLEN(onnx__Conv_739)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_740(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_740[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_740", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_740",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_740,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_740),
                                                .dataSize=BINLEN(onnx__Conv_740)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_2_dw_start_conv_Conv_output_0",
    "onnx__Conv_739",
    "onnx__Conv_740"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_742(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_742[] = {3, 3, 1, 640};
  VALIDATE(model.addTensor("onnx__Conv_742", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_742",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_742,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_742),
                                                .dataSize=BINLEN(onnx__Conv_742)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_743(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_743[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_743", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_743",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_743,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_743),
                                                .dataSize=BINLEN(onnx__Conv_743)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_742",
    "onnx__Conv_743"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_745(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_745[] = {1, 1, 640, 160};
  VALIDATE(model.addTensor("onnx__Conv_745", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_745",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_745,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_745),
                                                .dataSize=BINLEN(onnx__Conv_745)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_746(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_746[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_746", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_746",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_746,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_746),
                                                .dataSize=BINLEN(onnx__Conv_746)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_745",
    "onnx__Conv_746"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_2_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_2_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_2_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_2_Add[] = {
    "_blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_1_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_2_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_2_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_2_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_2_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_2_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_2_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_2_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_2_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_748(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_748[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_748", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_748",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_748,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_748),
                                                .dataSize=BINLEN(onnx__Conv_748)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_749(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_749[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_749", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_749",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_749,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_749),
                                                .dataSize=BINLEN(onnx__Conv_749)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_2_Add_output_0",
    "onnx__Conv_748",
    "onnx__Conv_749"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_751(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_751[] = {1, 1, 160, 640};
  VALIDATE(model.addTensor("onnx__Conv_751", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_751",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_751,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_751),
                                                .dataSize=BINLEN(onnx__Conv_751)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_752(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_752[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_752", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_752",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_752,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_752),
                                                .dataSize=BINLEN(onnx__Conv_752)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_3_dw_start_conv_Conv_output_0",
    "onnx__Conv_751",
    "onnx__Conv_752"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_754(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_754[] = {5, 5, 1, 640};
  VALIDATE(model.addTensor("onnx__Conv_754", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_754",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_754,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_754),
                                                .dataSize=BINLEN(onnx__Conv_754)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_755(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_755[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_755", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_755",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_755,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_755),
                                                .dataSize=BINLEN(onnx__Conv_755)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_754",
    "onnx__Conv_755"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_757(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_757[] = {1, 1, 640, 160};
  VALIDATE(model.addTensor("onnx__Conv_757", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_757",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_757,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_757),
                                                .dataSize=BINLEN(onnx__Conv_757)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_758(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_758[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_758", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_758",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_758,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_758),
                                                .dataSize=BINLEN(onnx__Conv_758)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_757",
    "onnx__Conv_758"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_3_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_3_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_3_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_3_Add[] = {
    "_blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_2_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_3_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_3_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_3_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_3_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_3_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_3_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_3_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_3_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_760(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_760[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_760", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_760",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_760,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_760),
                                                .dataSize=BINLEN(onnx__Conv_760)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_761(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_761[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_761", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_761",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_761,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_761),
                                                .dataSize=BINLEN(onnx__Conv_761)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_3_Add_output_0",
    "onnx__Conv_760",
    "onnx__Conv_761"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_763(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_763[] = {1, 1, 160, 640};
  VALIDATE(model.addTensor("onnx__Conv_763", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_763",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_763,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_763),
                                                .dataSize=BINLEN(onnx__Conv_763)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_764(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_764[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_764", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_764",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_764,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_764),
                                                .dataSize=BINLEN(onnx__Conv_764)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_4_dw_start_conv_Conv_output_0",
    "onnx__Conv_763",
    "onnx__Conv_764"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_766(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_766[] = {3, 3, 1, 640};
  VALIDATE(model.addTensor("onnx__Conv_766", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_766",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_766,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_766),
                                                .dataSize=BINLEN(onnx__Conv_766)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_767(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_767[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_767", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_767",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_767,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_767),
                                                .dataSize=BINLEN(onnx__Conv_767)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_766",
    "onnx__Conv_767"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_769(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_769[] = {1, 1, 640, 160};
  VALIDATE(model.addTensor("onnx__Conv_769", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_769",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_769,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_769),
                                                .dataSize=BINLEN(onnx__Conv_769)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_770(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_770[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_770", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_770",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_770,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_770),
                                                .dataSize=BINLEN(onnx__Conv_770)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_769",
    "onnx__Conv_770"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_4_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_4_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_4_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_4_Add[] = {
    "_blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_3_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_4_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_4_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_4_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_4_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_4_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_4_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_4_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_4_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_772(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_772[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_772", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_772",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_772,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_772),
                                                .dataSize=BINLEN(onnx__Conv_772)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_773(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_773[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_773", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_773",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_773,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_773),
                                                .dataSize=BINLEN(onnx__Conv_773)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_5_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_4_Add_output_0",
    "onnx__Conv_772",
    "onnx__Conv_773"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_775(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_775[] = {1, 1, 160, 640};
  VALIDATE(model.addTensor("onnx__Conv_775", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_775",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_775,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_775),
                                                .dataSize=BINLEN(onnx__Conv_775)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_776(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_776[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_776", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_776",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_776,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_776),
                                                .dataSize=BINLEN(onnx__Conv_776)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_5_dw_start_conv_Conv_output_0",
    "onnx__Conv_775",
    "onnx__Conv_776"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_778(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_778[] = {1, 1, 640, 160};
  VALIDATE(model.addTensor("onnx__Conv_778", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_778",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_778,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_778),
                                                .dataSize=BINLEN(onnx__Conv_778)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_779(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_779[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_779", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_779",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_779,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_779),
                                                .dataSize=BINLEN(onnx__Conv_779)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_778",
    "onnx__Conv_779"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_5_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_5_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_5_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_5_Add[] = {
    "_blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_4_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_5_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_5_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_5_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_5_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_5_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_5_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_5_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_5_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_781(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_781[] = {1, 1, 160, 320};
  VALIDATE(model.addTensor("onnx__Conv_781", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_781",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_781,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_781),
                                                .dataSize=BINLEN(onnx__Conv_781)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_782(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_782[] = {320};
  VALIDATE(model.addTensor("onnx__Conv_782", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_782",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_782,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_782),
                                                .dataSize=BINLEN(onnx__Conv_782)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_5_Add_output_0",
    "onnx__Conv_781",
    "onnx__Conv_782"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 320};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 320};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_784(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_784[] = {1, 1, 320, 160};
  VALIDATE(model.addTensor("onnx__Conv_784", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_784",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_784,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_784),
                                                .dataSize=BINLEN(onnx__Conv_784)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_785(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_785[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_785", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_785",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_785,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_785),
                                                .dataSize=BINLEN(onnx__Conv_785)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_784",
    "onnx__Conv_785"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_6_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_6_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_6_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_6_Add[] = {
    "_blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_5_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_6_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_6_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_6_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_6_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_6_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_6_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_6_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_6_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_787(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_787[] = {3, 3, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_787", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_787",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_787,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_787),
                                                .dataSize=BINLEN(onnx__Conv_787)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_788(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_788[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_788", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_788",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_788,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_788),
                                                .dataSize=BINLEN(onnx__Conv_788)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_7_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_6_Add_output_0",
    "onnx__Conv_787",
    "onnx__Conv_788"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_790(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_790[] = {1, 1, 160, 640};
  VALIDATE(model.addTensor("onnx__Conv_790", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_790",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_790,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_790),
                                                .dataSize=BINLEN(onnx__Conv_790)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_791(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_791[] = {640};
  VALIDATE(model.addTensor("onnx__Conv_791", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_791",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_791,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_791),
                                                .dataSize=BINLEN(onnx__Conv_791)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_7_dw_start_conv_Conv_output_0",
    "onnx__Conv_790",
    "onnx__Conv_791"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 640};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_793(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_793[] = {1, 1, 640, 160};
  VALIDATE(model.addTensor("onnx__Conv_793", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_793",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_793,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_793),
                                                .dataSize=BINLEN(onnx__Conv_793)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_794(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_794[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_794", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_794",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_794,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_794),
                                                .dataSize=BINLEN(onnx__Conv_794)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_793",
    "onnx__Conv_794"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_2_blocks_2_7_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_2_blocks_2_7_Add */
  Qnn_Param_t params__blocks_blocks_2_blocks_2_7_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_2_blocks_2_7_Add[] = {
    "_blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_2_blocks_2_6_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_2_blocks_2_7_Add_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_2_blocks_2_7_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_2_blocks_2_7_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_2_blocks_2_7_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_2_blocks_2_7_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_2_blocks_2_7_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_2_blocks_2_7_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_2_blocks_2_7_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_796(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_796[] = {5, 5, 1, 160};
  VALIDATE(model.addTensor("onnx__Conv_796", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_796",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_796,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_796),
                                                .dataSize=BINLEN(onnx__Conv_796)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_797(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_797[] = {160};
  VALIDATE(model.addTensor("onnx__Conv_797", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_797",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_797,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_797),
                                                .dataSize=BINLEN(onnx__Conv_797)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_0_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv[] = {
    "_blocks_blocks_2_blocks_2_7_Add_output_0",
    "onnx__Conv_796",
    "onnx__Conv_797"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_output_0[] = {1, 14, 14, 160};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_799(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_799[] = {1, 1, 160, 960};
  VALIDATE(model.addTensor("onnx__Conv_799", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_799",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_799,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_799),
                                                .dataSize=BINLEN(onnx__Conv_799)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_800(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_800[] = {960};
  VALIDATE(model.addTensor("onnx__Conv_800", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_800",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_800,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_800),
                                                .dataSize=BINLEN(onnx__Conv_800)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_0_dw_start_conv_Conv_output_0",
    "onnx__Conv_799",
    "onnx__Conv_800"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_output_0[] = {1, 14, 14, 960};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu_output_0[] = {1, 14, 14, 960};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_802(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_802[] = {5, 5, 1, 960};
  VALIDATE(model.addTensor("onnx__Conv_802", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_802",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_802,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_802),
                                                .dataSize=BINLEN(onnx__Conv_802)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_803(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_803[] = {960};
  VALIDATE(model.addTensor("onnx__Conv_803", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_803",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_803,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_803),
                                                .dataSize=BINLEN(onnx__Conv_803)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_stride[] = {2, 2};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_802",
    "onnx__Conv_803"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_output_0[] = {1, 7, 7, 960};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu_output_0[] = {1, 7, 7, 960};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_805(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_805[] = {1, 1, 960, 256};
  VALIDATE(model.addTensor("onnx__Conv_805", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_805",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_805,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_805),
                                                .dataSize=BINLEN(onnx__Conv_805)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_806(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_806[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_806", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_806",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_806,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_806),
                                                .dataSize=BINLEN(onnx__Conv_806)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_805",
    "onnx__Conv_806"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_808(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_808[] = {5, 5, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_808", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_808",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_808,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_808),
                                                .dataSize=BINLEN(onnx__Conv_808)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_809(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_809[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_809", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_809",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_809,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_809),
                                                .dataSize=BINLEN(onnx__Conv_809)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_output_0",
    "onnx__Conv_808",
    "onnx__Conv_809"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_811(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_811[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_811", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_811",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_811,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_811),
                                                .dataSize=BINLEN(onnx__Conv_811)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_812(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_812[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_812", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_812",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_812,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_812),
                                                .dataSize=BINLEN(onnx__Conv_812)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_1_dw_start_conv_Conv_output_0",
    "onnx__Conv_811",
    "onnx__Conv_812"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_814(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_814[] = {5, 5, 1, 1024};
  VALIDATE(model.addTensor("onnx__Conv_814", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_814",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_814,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_814),
                                                .dataSize=BINLEN(onnx__Conv_814)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_815(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_815[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_815", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_815",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_815,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_815),
                                                .dataSize=BINLEN(onnx__Conv_815)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_814",
    "onnx__Conv_815"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_817(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_817[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_817", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_817",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_817,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_817),
                                                .dataSize=BINLEN(onnx__Conv_817)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_818(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_818[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_818", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_818",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_818,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_818),
                                                .dataSize=BINLEN(onnx__Conv_818)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_817",
    "onnx__Conv_818"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_1_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_1_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_1_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_1_Add[] = {
    "_blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_1_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_1_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_1_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_1_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_1_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_1_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_1_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_1_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_820(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_820[] = {3, 3, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_820", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_820",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_820,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_820),
                                                .dataSize=BINLEN(onnx__Conv_820)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_821(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_821[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_821", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_821",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_821,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_821),
                                                .dataSize=BINLEN(onnx__Conv_821)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_1_Add_output_0",
    "onnx__Conv_820",
    "onnx__Conv_821"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_823(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_823[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_823", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_823",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_823,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_823),
                                                .dataSize=BINLEN(onnx__Conv_823)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_824(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_824[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_824", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_824",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_824,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_824),
                                                .dataSize=BINLEN(onnx__Conv_824)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_2_dw_start_conv_Conv_output_0",
    "onnx__Conv_823",
    "onnx__Conv_824"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_826(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_826[] = {5, 5, 1, 1024};
  VALIDATE(model.addTensor("onnx__Conv_826", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_826",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_826,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_826),
                                                .dataSize=BINLEN(onnx__Conv_826)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_827(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_827[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_827", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_827",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_827,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_827),
                                                .dataSize=BINLEN(onnx__Conv_827)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_826",
    "onnx__Conv_827"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_829(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_829[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_829", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_829",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_829,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_829),
                                                .dataSize=BINLEN(onnx__Conv_829)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_830(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_830[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_830", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_830",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_830,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_830),
                                                .dataSize=BINLEN(onnx__Conv_830)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_829",
    "onnx__Conv_830"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_2_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_2_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_2_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_2_Add[] = {
    "_blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_1_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_2_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_2_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_2_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_2_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_2_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_2_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_2_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_2_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_832(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_832[] = {3, 3, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_832", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_832",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_832,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_832),
                                                .dataSize=BINLEN(onnx__Conv_832)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_833(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_833[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_833", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_833",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_833,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_833),
                                                .dataSize=BINLEN(onnx__Conv_833)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_2_Add_output_0",
    "onnx__Conv_832",
    "onnx__Conv_833"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_835(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_835[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_835", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_835",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_835,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_835),
                                                .dataSize=BINLEN(onnx__Conv_835)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_836(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_836[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_836", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_836",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_836,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_836),
                                                .dataSize=BINLEN(onnx__Conv_836)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_3_dw_start_conv_Conv_output_0",
    "onnx__Conv_835",
    "onnx__Conv_836"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_838(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_838[] = {5, 5, 1, 1024};
  VALIDATE(model.addTensor("onnx__Conv_838", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_838",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_838,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_838),
                                                .dataSize=BINLEN(onnx__Conv_838)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_839(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_839[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_839", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_839",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_839,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_839),
                                                .dataSize=BINLEN(onnx__Conv_839)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_838",
    "onnx__Conv_839"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_841(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_841[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_841", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_841",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_841,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_841),
                                                .dataSize=BINLEN(onnx__Conv_841)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_842(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_842[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_842", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_842",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_842,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_842),
                                                .dataSize=BINLEN(onnx__Conv_842)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_841",
    "onnx__Conv_842"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_3_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_3_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_3_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_3_Add[] = {
    "_blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_2_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_3_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_3_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_3_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_3_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_3_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_3_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_3_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_3_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_844(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_844[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_844", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_844",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_844,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_844),
                                                .dataSize=BINLEN(onnx__Conv_844)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_845(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_845[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_845", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_845",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_845,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_845),
                                                .dataSize=BINLEN(onnx__Conv_845)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_3_Add_output_0",
    "onnx__Conv_844",
    "onnx__Conv_845"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_847(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_847[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_847", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_847",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_847,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_847),
                                                .dataSize=BINLEN(onnx__Conv_847)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_848(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_848[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_848", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_848",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_848,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_848),
                                                .dataSize=BINLEN(onnx__Conv_848)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_847",
    "onnx__Conv_848"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_4_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_4_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_4_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_4_Add[] = {
    "_blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_3_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_4_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_4_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_4_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_4_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_4_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_4_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_4_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_4_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_850(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_850[] = {3, 3, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_850", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_850",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_850,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_850),
                                                .dataSize=BINLEN(onnx__Conv_850)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_851(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_851[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_851", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_851",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_851,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_851),
                                                .dataSize=BINLEN(onnx__Conv_851)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_5_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_4_Add_output_0",
    "onnx__Conv_850",
    "onnx__Conv_851"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_853(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_853[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_853", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_853",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_853,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_853),
                                                .dataSize=BINLEN(onnx__Conv_853)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_854(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_854[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_854", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_854",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_854,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_854),
                                                .dataSize=BINLEN(onnx__Conv_854)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_5_dw_start_conv_Conv_output_0",
    "onnx__Conv_853",
    "onnx__Conv_854"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_856(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_856[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_856", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_856",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_856,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_856),
                                                .dataSize=BINLEN(onnx__Conv_856)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_857(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_857[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_857", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_857",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_857,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_857),
                                                .dataSize=BINLEN(onnx__Conv_857)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_856",
    "onnx__Conv_857"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_5_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_5_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_5_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_5_Add[] = {
    "_blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_4_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_5_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_5_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_5_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_5_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_5_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_5_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_5_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_5_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_859(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_859[] = {3, 3, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_859", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_859",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_859,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_859),
                                                .dataSize=BINLEN(onnx__Conv_859)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_860(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_860[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_860", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_860",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_860,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_860),
                                                .dataSize=BINLEN(onnx__Conv_860)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_pad_amount[] = {1, 1, 1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_5_Add_output_0",
    "onnx__Conv_859",
    "onnx__Conv_860"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_862(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_862[] = {1, 1, 256, 512};
  VALIDATE(model.addTensor("onnx__Conv_862", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_862",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_862,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_862),
                                                .dataSize=BINLEN(onnx__Conv_862)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_863(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_863[] = {512};
  VALIDATE(model.addTensor("onnx__Conv_863", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_863",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_863,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_863),
                                                .dataSize=BINLEN(onnx__Conv_863)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_6_dw_start_conv_Conv_output_0",
    "onnx__Conv_862",
    "onnx__Conv_863"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 512};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 512};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_865(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_865[] = {5, 5, 1, 512};
  VALIDATE(model.addTensor("onnx__Conv_865", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_865",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_865,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_865),
                                                .dataSize=BINLEN(onnx__Conv_865)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_866(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_866[] = {512};
  VALIDATE(model.addTensor("onnx__Conv_866", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_866",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_866,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_866),
                                                .dataSize=BINLEN(onnx__Conv_866)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_865",
    "onnx__Conv_866"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_output_0[] = {1, 7, 7, 512};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu_output_0[] = {1, 7, 7, 512};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_868(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_868[] = {1, 1, 512, 256};
  VALIDATE(model.addTensor("onnx__Conv_868", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_868",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_868,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_868),
                                                .dataSize=BINLEN(onnx__Conv_868)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_869(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_869[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_869", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_869",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_869,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_869),
                                                .dataSize=BINLEN(onnx__Conv_869)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_868",
    "onnx__Conv_869"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_6_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_6_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_6_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_6_Add[] = {
    "_blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_5_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_6_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_6_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_6_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_6_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_6_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_6_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_6_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_6_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_871(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_871[] = {5, 5, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_871", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_871",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_871,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_871),
                                                .dataSize=BINLEN(onnx__Conv_871)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_872(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_872[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_872", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_872",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_872,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_872),
                                                .dataSize=BINLEN(onnx__Conv_872)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_6_Add_output_0",
    "onnx__Conv_871",
    "onnx__Conv_872"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_874(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_874[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_874", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_874",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_874,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_874),
                                                .dataSize=BINLEN(onnx__Conv_874)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_875(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_875[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_875", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_875",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_875,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_875),
                                                .dataSize=BINLEN(onnx__Conv_875)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_7_dw_start_conv_Conv_output_0",
    "onnx__Conv_874",
    "onnx__Conv_875"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_877(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_877[] = {5, 5, 1, 1024};
  VALIDATE(model.addTensor("onnx__Conv_877", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_877",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_877,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_877),
                                                .dataSize=BINLEN(onnx__Conv_877)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_878(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_878[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_878", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_878",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_878,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_878),
                                                .dataSize=BINLEN(onnx__Conv_878)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_877",
    "onnx__Conv_878"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_880(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_880[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_880", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_880",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_880,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_880),
                                                .dataSize=BINLEN(onnx__Conv_880)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_881(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_881[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_881", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_881",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_881,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_881),
                                                .dataSize=BINLEN(onnx__Conv_881)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu_output_0",
    "onnx__Conv_880",
    "onnx__Conv_881"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_7_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_7_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_7_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_7_Add[] = {
    "_blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_6_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_7_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_7_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_7_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_7_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_7_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_7_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_7_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_7_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_883(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_883[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_883", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_883",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_883,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_883),
                                                .dataSize=BINLEN(onnx__Conv_883)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_884(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_884[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_884", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_884",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_884,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_884),
                                                .dataSize=BINLEN(onnx__Conv_884)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_7_Add_output_0",
    "onnx__Conv_883",
    "onnx__Conv_884"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_886(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_886[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_886", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_886",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_886,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_886),
                                                .dataSize=BINLEN(onnx__Conv_886)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_887(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_887[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_887", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_887",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_887,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_887),
                                                .dataSize=BINLEN(onnx__Conv_887)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_886",
    "onnx__Conv_887"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_8_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_8_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_8_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_8_Add[] = {
    "_blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_7_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_8_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_8_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_8_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_8_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_8_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_8_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_8_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_8_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_889(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_889[] = {1, 1, 256, 1024};
  VALIDATE(model.addTensor("onnx__Conv_889", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_889",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_889,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_889),
                                                .dataSize=BINLEN(onnx__Conv_889)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_890(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_890[] = {1024};
  VALIDATE(model.addTensor("onnx__Conv_890", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_890",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_890,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_890),
                                                .dataSize=BINLEN(onnx__Conv_890)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_8_Add_output_0",
    "onnx__Conv_889",
    "onnx__Conv_890"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 1024};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_892(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_892[] = {1, 1, 1024, 256};
  VALIDATE(model.addTensor("onnx__Conv_892", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_892",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_892,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_892),
                                                .dataSize=BINLEN(onnx__Conv_892)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_893(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_893[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_893", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_893",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_893,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_893),
                                                .dataSize=BINLEN(onnx__Conv_893)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_892",
    "onnx__Conv_893"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_9_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_9_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_9_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_9_Add[] = {
    "_blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_8_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_9_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_9_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_9_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_9_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_9_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_9_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_9_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_9_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_895(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_895[] = {5, 5, 1, 256};
  VALIDATE(model.addTensor("onnx__Conv_895", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_895",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_895,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_895),
                                                .dataSize=BINLEN(onnx__Conv_895)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_896(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_896[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_896", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_896",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_896,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_896),
                                                .dataSize=BINLEN(onnx__Conv_896)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_10_dw_start_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_pad_amount[] = {2, 2, 2, 2};
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_9_Add_output_0",
    "onnx__Conv_895",
    "onnx__Conv_896"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "DepthWiseConv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv, // Node Params
                         3, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_898(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_898[] = {1, 1, 256, 512};
  VALIDATE(model.addTensor("onnx__Conv_898", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_898",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_898,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_898),
                                                .dataSize=BINLEN(onnx__Conv_898)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_899(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_899[] = {512};
  VALIDATE(model.addTensor("onnx__Conv_899", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_899",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_899,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_899),
                                                .dataSize=BINLEN(onnx__Conv_899)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_10_dw_start_conv_Conv_output_0",
    "onnx__Conv_898",
    "onnx__Conv_899"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_output_0[] = {1, 7, 7, 512};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu[] = {
    "_blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu_output_0[] = {1, 7, 7, 512};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_901(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_901[] = {1, 1, 512, 256};
  VALIDATE(model.addTensor("onnx__Conv_901", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_901",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_901,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_901),
                                                .dataSize=BINLEN(onnx__Conv_901)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_902(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_902[] = {256};
  VALIDATE(model.addTensor("onnx__Conv_902", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_902",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_902,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_902),
                                                .dataSize=BINLEN(onnx__Conv_902)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv */
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu_output_0",
    "onnx__Conv_901",
    "onnx__Conv_902"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_3_blocks_3_10_Add(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_3_blocks_3_10_Add */
  Qnn_Param_t params__blocks_blocks_3_blocks_3_10_Add[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_3_blocks_3_10_Add[] = {
    "_blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv_output_0",
    "_blocks_blocks_3_blocks_3_9_Add_output_0"
  };
  uint32_t dimensions__blocks_blocks_3_blocks_3_10_Add_output_0[] = {1, 7, 7, 256};
  Qnn_Tensor_t outputs__blocks_blocks_3_blocks_3_10_Add[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_3_blocks_3_10_Add_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_3_blocks_3_10_Add_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_3_blocks_3_10_Add", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseBinary", // Qnn Node Type
                         params__blocks_blocks_3_blocks_3_10_Add, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_3_blocks_3_10_Add, // Input Tensor Names
                         2, // Num Input Tensor Names
                         outputs__blocks_blocks_3_blocks_3_10_Add, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_904(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_904[] = {1, 1, 256, 960};
  VALIDATE(model.addTensor("onnx__Conv_904", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_904",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_904,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_904),
                                                .dataSize=BINLEN(onnx__Conv_904)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_905(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_905[] = {960};
  VALIDATE(model.addTensor("onnx__Conv_905", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_905",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_905,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_905),
                                                .dataSize=BINLEN(onnx__Conv_905)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_4_blocks_4_0_conv_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_4_blocks_4_0_conv_Conv */
  uint32_t dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_dilation[] = {2};
  uint32_t _blocks_blocks_4_blocks_4_0_conv_Conv_dilation[] = {1, 1};
  uint32_t dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_pad_amount[] = {2, 2};
  uint32_t _blocks_blocks_4_blocks_4_0_conv_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_stride[] = {2};
  uint32_t _blocks_blocks_4_blocks_4_0_conv_Conv_stride[] = {1, 1};
  Qnn_Param_t params__blocks_blocks_4_blocks_4_0_conv_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_4_blocks_4_0_conv_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_4_blocks_4_0_conv_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_4_blocks_4_0_conv_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_4_blocks_4_0_conv_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_4_blocks_4_0_conv_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_blocks_blocks_4_blocks_4_0_conv_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__blocks_blocks_4_blocks_4_0_conv_Conv[] = {
    "_blocks_blocks_3_blocks_3_10_Add_output_0",
    "onnx__Conv_904",
    "onnx__Conv_905"
  };
  uint32_t dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_output_0[] = {1, 7, 7, 960};
  Qnn_Tensor_t outputs__blocks_blocks_4_blocks_4_0_conv_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_4_blocks_4_0_conv_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_4_blocks_4_0_conv_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_4_blocks_4_0_conv_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__blocks_blocks_4_blocks_4_0_conv_Conv, // Node Params
                         5, // Num Node Params
                         inputs__blocks_blocks_4_blocks_4_0_conv_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__blocks_blocks_4_blocks_4_0_conv_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__blocks_blocks_4_blocks_4_0_bn1_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _blocks_blocks_4_blocks_4_0_bn1_act_Relu */
  Qnn_Param_t params__blocks_blocks_4_blocks_4_0_bn1_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__blocks_blocks_4_blocks_4_0_bn1_act_Relu[] = {
    "_blocks_blocks_4_blocks_4_0_conv_Conv_output_0"
  };
  uint32_t dimensions__blocks_blocks_4_blocks_4_0_bn1_act_Relu_output_0[] = {1, 7, 7, 960};
  Qnn_Tensor_t outputs__blocks_blocks_4_blocks_4_0_bn1_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_blocks_blocks_4_blocks_4_0_bn1_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__blocks_blocks_4_blocks_4_0_bn1_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_blocks_blocks_4_blocks_4_0_bn1_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__blocks_blocks_4_blocks_4_0_bn1_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__blocks_blocks_4_blocks_4_0_bn1_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__blocks_blocks_4_blocks_4_0_bn1_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__global_pool_pool_GlobalAveragePool(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _global_pool_pool_GlobalAveragePool */
  uint32_t dimensions__global_pool_pool_GlobalAveragePool_filter_size[] = {2};
  uint32_t _global_pool_pool_GlobalAveragePool_filter_size[] = {7, 7};
  uint32_t dimensions__global_pool_pool_GlobalAveragePool_pad_amount[] = {2, 2};
  uint32_t _global_pool_pool_GlobalAveragePool_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__global_pool_pool_GlobalAveragePool_stride[] = {2};
  uint32_t _global_pool_pool_GlobalAveragePool_stride[] = {7, 7};
  Qnn_Param_t params__global_pool_pool_GlobalAveragePool[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="filter_size",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_global_pool_pool_GlobalAveragePool_filter_size",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__global_pool_pool_GlobalAveragePool_filter_size,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_global_pool_pool_GlobalAveragePool_filter_size,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_global_pool_pool_GlobalAveragePool_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__global_pool_pool_GlobalAveragePool_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_global_pool_pool_GlobalAveragePool_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_global_pool_pool_GlobalAveragePool_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__global_pool_pool_GlobalAveragePool_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_global_pool_pool_GlobalAveragePool_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="count_pad_for_edges",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__global_pool_pool_GlobalAveragePool[] = {
    "_blocks_blocks_4_blocks_4_0_bn1_act_Relu_output_0"
  };
  uint32_t dimensions__global_pool_pool_GlobalAveragePool_output_0[] = {1, 1, 1, 960};
  Qnn_Tensor_t outputs__global_pool_pool_GlobalAveragePool[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_global_pool_pool_GlobalAveragePool_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__global_pool_pool_GlobalAveragePool_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_global_pool_pool_GlobalAveragePool", // Node Name
                         "qti.aisw", // Package Name
                         "PoolAvg2d", // Qnn Node Type
                         params__global_pool_pool_GlobalAveragePool, // Node Params
                         4, // Num Node Params
                         inputs__global_pool_pool_GlobalAveragePool, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__global_pool_pool_GlobalAveragePool, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_907(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_907[] = {1, 1, 960, 1280};
  VALIDATE(model.addTensor("onnx__Conv_907", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_907",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 4,
                                 .dimensions=dimensions_onnx__Conv_907,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_907),
                                                .dataSize=BINLEN(onnx__Conv_907)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_onnx__Conv_908(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_onnx__Conv_908[] = {1280};
  VALIDATE(model.addTensor("onnx__Conv_908", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "onnx__Conv_908",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_onnx__Conv_908,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(onnx__Conv_908),
                                                .dataSize=BINLEN(onnx__Conv_908)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__conv_head_Conv(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _conv_head_Conv */
  uint32_t dimensions__conv_head_Conv_dilation[] = {2};
  uint32_t _conv_head_Conv_dilation[] = {1, 1};
  uint32_t dimensions__conv_head_Conv_pad_amount[] = {2, 2};
  uint32_t _conv_head_Conv_pad_amount[] = {0, 0, 0, 0};
  uint32_t dimensions__conv_head_Conv_stride[] = {2};
  uint32_t _conv_head_Conv_stride[] = {1, 1};
  Qnn_Param_t params__conv_head_Conv[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="dilation",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_head_Conv_dilation",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__conv_head_Conv_dilation,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_conv_head_Conv_dilation,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="pad_amount",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_head_Conv_pad_amount",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions__conv_head_Conv_pad_amount,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_conv_head_Conv_pad_amount,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="stride",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_head_Conv_stride",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__conv_head_Conv_stride,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_conv_head_Conv_stride,
                           .dataSize=8}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="group",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 1}}}},
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="reuse_sparse_indices",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_BOOL_8, {.bool8Value = 0}}}}
  };
  const char*  inputs__conv_head_Conv[] = {
    "_global_pool_pool_GlobalAveragePool_output_0",
    "onnx__Conv_907",
    "onnx__Conv_908"
  };
  uint32_t dimensions__conv_head_Conv_output_0[] = {1, 1, 1, 1280};
  Qnn_Tensor_t outputs__conv_head_Conv[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_conv_head_Conv_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__conv_head_Conv_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_conv_head_Conv", // Node Name
                         "qti.aisw", // Package Name
                         "Conv2d", // Qnn Node Type
                         params__conv_head_Conv, // Node Params
                         5, // Num Node Params
                         inputs__conv_head_Conv, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__conv_head_Conv, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__norm_head_act_Relu(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _norm_head_act_Relu */
  Qnn_Param_t params__norm_head_act_Relu[] = {
    {.paramType=QNN_PARAMTYPE_SCALAR,
     .name="operation",
     {.scalarParam= (Qnn_Scalar_t) {QNN_DATATYPE_UINT_32, {.uint32Value = 4}}}}
  };
  const char*  inputs__norm_head_act_Relu[] = {
    "_conv_head_Conv_output_0"
  };
  uint32_t dimensions__norm_head_act_Relu_output_0[] = {1, 1, 1, 1280};
  Qnn_Tensor_t outputs__norm_head_act_Relu[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_norm_head_act_Relu_output_0",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__norm_head_act_Relu_output_0,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_norm_head_act_Relu", // Node Name
                         "qti.aisw", // Package Name
                         "ElementWiseNeuron", // Qnn Node Type
                         params__norm_head_act_Relu, // Node Params
                         1, // Num Node Params
                         inputs__norm_head_act_Relu, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__norm_head_act_Relu, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addNode__norm_head_act_Relu_output_0_nchw(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _norm_head_act_Relu_output_0_nchw */
  uint32_t dimensions__norm_head_act_Relu_output_0_nchw_perm[] = {4};
  uint32_t _norm_head_act_Relu_output_0_nchw_perm[] = {0, 3, 1, 2};
  Qnn_Param_t params__norm_head_act_Relu_output_0_nchw[] = {
    {.paramType=QNN_PARAMTYPE_TENSOR,
     .name="perm",
     {.tensorParam=(Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_norm_head_act_Relu_output_0_nchw_perm",
            .type= QNN_TENSOR_TYPE_STATIC,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_UINT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 1,
            .dimensions=dimensions__norm_head_act_Relu_output_0_nchw_perm,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=(uint8_t*)_norm_head_act_Relu_output_0_nchw_perm,
                           .dataSize=16}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}}}
  };
  const char*  inputs__norm_head_act_Relu_output_0_nchw[] = {
    "_norm_head_act_Relu_output_0"
  };
  uint32_t dimensions__norm_head_act_Relu_output_0_nchw[] = {1, 1280, 1, 1};
  Qnn_Tensor_t outputs__norm_head_act_Relu_output_0_nchw[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "_norm_head_act_Relu_output_0_nchw",
            .type= QNN_TENSOR_TYPE_NATIVE,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 4,
            .dimensions=dimensions__norm_head_act_Relu_output_0_nchw,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_norm_head_act_Relu_output_0_nchw", // Node Name
                         "qti.aisw", // Package Name
                         "Transpose", // Qnn Node Type
                         params__norm_head_act_Relu_output_0_nchw, // Node Params
                         1, // Num Node Params
                         inputs__norm_head_act_Relu_output_0_nchw, // Input Tensor Names
                         1, // Num Input Tensor Names
                         outputs__norm_head_act_Relu_output_0_nchw, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

static ModelError_t addTensor_classifier_weight_permute(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_classifier_weight_permute[] = {1000, 1280};
  VALIDATE(model.addTensor("classifier_weight_permute", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "classifier_weight_permute",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 2,
                                 .dimensions=dimensions_classifier_weight_permute,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(classifier_weight_permute),
                                                .dataSize=BINLEN(classifier_weight_permute)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addTensor_classifier_bias(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;
  uint32_t dimensions_classifier_bias[] = {1000};
  VALIDATE(model.addTensor("classifier_bias", // Tensor Name
                           (Qnn_Tensor_t) {
                               .version= QNN_TENSOR_VERSION_2,
                               {.v2= {
                                 .id=0,
                                 .name= "classifier_bias",
                                 .type= QNN_TENSOR_TYPE_STATIC,
                                 .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
                                 .dataType= QNN_DATATYPE_FLOAT_32,
                                 .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                                                    QNN_QUANTIZATION_ENCODING_UNDEFINED,
                                                    {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
                                 .rank= 1,
                                 .dimensions=dimensions_classifier_bias,
                                 .memType= QNN_TENSORMEMTYPE_RAW,
                                 {.clientBuf= { .data=BINVARSTART(classifier_bias),
                                                .dataSize=BINLEN(classifier_bias)}},
                                 .isDynamicDimensions= nullptr,
                                 .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                                                  .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
                                 .isProduced= 0}}}
  ), err);
  return err;
}

static ModelError_t addNode__classifier_Gemm(QnnModel& model){
  ModelError_t err = MODEL_NO_ERROR;

  /* ADDING NODE FOR _classifier_Gemm */
  const char*  inputs__classifier_Gemm[] = {
    "_norm_head_act_Relu_output_0_nchw",
    "classifier_weight_permute",
    "classifier_bias"
  };
  uint32_t dimensions_output[] = {1, 1000};
  Qnn_Tensor_t outputs__classifier_Gemm[] = {
    (Qnn_Tensor_t) {
          .version= QNN_TENSOR_VERSION_2,
          {.v2= {
            .id=0,
            .name= "output",
            .type= QNN_TENSOR_TYPE_APP_READ,
            .dataFormat= QNN_TENSOR_DATA_FORMAT_DENSE,
            .dataType= QNN_DATATYPE_FLOAT_32,
            .quantizeParams= { QNN_DEFINITION_UNDEFINED,
                               QNN_QUANTIZATION_ENCODING_UNDEFINED,
                               {.scaleOffsetEncoding= {.scale= 0.0000000000000000000000000000000000000000f, .offset= 0}}},
            .rank= 2,
            .dimensions=dimensions_output,
            .memType= QNN_TENSORMEMTYPE_RAW,
            {.clientBuf= { .data=nullptr,
                           .dataSize=0}},
            .isDynamicDimensions= nullptr,
            .sparseParams= { QNN_SPARSE_LAYOUT_UNDEFINED,
                             .hybridCoo= {.numSpecifiedElements= 0, .numSparseDimensions= 0}},
            .isProduced= 0}}}
  };
  VALIDATE(model.addNode(QNN_OPCONFIG_VERSION_1, // Op_Config_t Version
                         "_classifier_Gemm", // Node Name
                         "qti.aisw", // Package Name
                         "FullyConnected", // Qnn Node Type
                         nullptr, // Node Params
                         0, // Num Node Params
                         inputs__classifier_Gemm, // Input Tensor Names
                         3, // Num Input Tensor Names
                         outputs__classifier_Gemm, // Output Tensors 
                         1// Num Output Tensors 
  ), err);
  return err;
}

QNN_API
ModelError_t QnnModel_composeGraphs(Qnn_BackendHandle_t backendHandle,
                                    QNN_INTERFACE_VER_TYPE interface,
                                    Qnn_ContextHandle_t contextHandle,
                                    const GraphConfigInfo_t** graphsConfigInfo,
                                    const uint32_t numGraphsConfigInfo,
                                    GraphInfoPtr_t** graphsInfo,
                                    uint32_t* numGraphsInfo,
                                    bool debug,
                                    QnnLog_Callback_t logCallback,
                                    QnnLog_Level_t maxLogLevel) {

  ModelError_t err = MODEL_NO_ERROR;

  /* model/graph for mobilenetv4*/
  QnnModel mobilenetv4;
  const QnnGraph_Config_t** graphConfigs = nullptr;
  VALIDATE(getQnnGraphConfigFromInfo("mobilenetv4", graphsConfigInfo, numGraphsConfigInfo, graphConfigs), err);
  VALIDATE(mobilenetv4.initialize(backendHandle, interface, contextHandle, "mobilenetv4", debug, DO_GRAPH_NODE_VALIDATIONS, graphConfigs), err);
  VALIDATE(addTensor_input(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_679(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_680(mobilenetv4), err);
  VALIDATE(addNode__conv_stem_Conv(mobilenetv4), err);
  VALIDATE(addNode__bn1_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_682(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_683(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_0_blocks_0_0_conv_exp_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_0_blocks_0_0_bn1_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_685(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_686(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_0_blocks_0_0_conv_pwl_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_688(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_689(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_0_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_691(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_692(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_0_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_0_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_694(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_695(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_0_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_0_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_697(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_698(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_0_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_700(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_701(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_703(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_704(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_706(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_707(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_709(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_710(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_1_blocks_1_1_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_712(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_713(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_0_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_715(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_716(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_0_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_0_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_718(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_719(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_0_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_0_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_721(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_722(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_0_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_724(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_725(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_727(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_728(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_730(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_731(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_733(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_734(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_1_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_736(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_737(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_739(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_740(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_742(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_743(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_745(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_746(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_2_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_748(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_749(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_751(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_752(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_754(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_755(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_757(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_758(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_3_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_760(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_761(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_763(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_764(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_766(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_767(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_769(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_770(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_4_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_772(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_773(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_5_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_775(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_776(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_5_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_5_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_778(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_779(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_5_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_5_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_781(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_782(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_6_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_6_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_784(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_785(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_6_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_6_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_787(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_788(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_7_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_790(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_791(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_7_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_7_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_793(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_794(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_7_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_2_blocks_2_7_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_796(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_797(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_0_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_799(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_800(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_0_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_0_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_802(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_803(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_0_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_0_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_805(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_806(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_0_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_808(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_809(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_811(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_812(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_814(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_815(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_817(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_818(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_1_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_820(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_821(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_823(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_824(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_826(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_827(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_829(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_830(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_2_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_832(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_833(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_835(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_836(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_838(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_839(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_841(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_842(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_3_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_844(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_845(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_4_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_4_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_847(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_848(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_4_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_4_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_850(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_851(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_5_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_853(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_854(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_5_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_5_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_856(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_857(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_5_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_5_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_859(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_860(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_862(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_863(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_865(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_866(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_868(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_869(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_6_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_871(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_872(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_874(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_875(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_877(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_878(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_dw_mid_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_dw_mid_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_880(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_881(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_7_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_883(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_884(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_8_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_8_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_886(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_887(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_8_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_8_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_889(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_890(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_9_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_9_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_892(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_893(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_9_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_9_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_895(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_896(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_10_dw_start_conv_Conv(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_898(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_899(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_10_pw_exp_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_10_pw_exp_bn_act_Relu(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_901(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_902(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_10_pw_proj_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_3_blocks_3_10_Add(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_904(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_905(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_4_blocks_4_0_conv_Conv(mobilenetv4), err);
  VALIDATE(addNode__blocks_blocks_4_blocks_4_0_bn1_act_Relu(mobilenetv4), err);
  VALIDATE(addNode__global_pool_pool_GlobalAveragePool(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_907(mobilenetv4), err);
  VALIDATE(addTensor_onnx__Conv_908(mobilenetv4), err);
  VALIDATE(addNode__conv_head_Conv(mobilenetv4), err);
  VALIDATE(addNode__norm_head_act_Relu(mobilenetv4), err);
  VALIDATE(addNode__norm_head_act_Relu_output_0_nchw(mobilenetv4), err);
  VALIDATE(addTensor_classifier_weight_permute(mobilenetv4), err);
  VALIDATE(addTensor_classifier_bias(mobilenetv4), err);
  VALIDATE(addNode__classifier_Gemm(mobilenetv4), err);

  // Add all models to array to get graphsInfo
  QnnModel* models [] = {&mobilenetv4};
  uint32_t numModels = 1;

  // Populate the constructed graphs in provided output variables
  VALIDATE(getGraphInfoFromModels(*models, numModels, graphsInfo), err);
  *numGraphsInfo = numModels;

  return err;

} // PREPARE_GRAPHS

QNN_API
ModelError_t QnnModel_freeGraphsInfo(GraphInfoPtr_t** graphsInfo, uint32_t numGraphsInfo){
  return qnn_wrapper_api::freeGraphsInfo(graphsInfo, numGraphsInfo);
} // FREEGRAPHINFO

}