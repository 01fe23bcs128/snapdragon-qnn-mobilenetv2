# Snapdragon QNN Deployment Pipeline (MobileNetV2)

Production-stable pipeline for converting a PyTorch model to Qualcomm QNN format.

## Pipeline

PyTorch 1.13.1  
→ ONNX (opset 13, static shapes)  
→ QNN SDK (AI Engine Direct)  
→ .cpp + .bin  
→ Snapdragon DSP/NPU Runtime  

---

## Environment Setup

```bash
python3 -m venv qnn_env
source qnn_env/bin/activate
pip install --upgrade pip
pip install -r requirements.txt