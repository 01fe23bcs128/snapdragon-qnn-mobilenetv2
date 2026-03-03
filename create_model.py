import torch
import torchvision.models as models

model = models.mobilenet_v2(weights=None)
model.eval()

dummy = torch.randn(1, 3, 224, 224)

torch.onnx.export(
    model,
    dummy,
    "onnx/mobilenet_v2.onnx",
    opset_version=13,
    input_names=["input"],
    output_names=["output"],
    dynamic_axes=None,
    training=torch.onnx.TrainingMode.EVAL,
    do_constant_folding=True,
)

print("ONNX export complete.")