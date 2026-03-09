# Snapdragon QNN Deployment Pipeline (MobileNetV2)

This repository demonstrates an **end-to-end deployment pipeline for running a deep learning model on Qualcomm Snapdragon devices using the Qualcomm Neural Network (QNN) SDK**.

The project converts a **PyTorch model (.pt)** into **ONNX format**, then compiles it into a **QNN runtime library (.so)** that can run efficiently on **Snapdragon AI hardware accelerators**.

The goal of this project is to demonstrate **edge AI deployment for mobile devices**, enabling **low-latency on-device inference without relying on cloud computation**.

---

# Deployment Pipeline

```
PyTorch Model (.pt)
        │
        ▼
ONNX Export (.onnx)
        │
        ▼
QNN Model Conversion
        │
        ▼
QNN Runtime Compilation (.so)
        │
        ▼
Snapdragon AI Hardware Inference
```

This pipeline demonstrates how a deep learning model can be **optimized and deployed for Snapdragon processors using Qualcomm's QNN SDK**.

---

# Repository Structure

```
snapdragon-qnn-mobilenetv2
│
├── android_build/
│   └── aarch64-android/
│       └── libmobilenetv4.so
│
├── dataset_eval/              # Evaluation dataset
├── dataset_raw/               # Raw dataset used for preprocessing
│
├── deploy/                    # Deployment scripts
├── deploy_htp_runtime/        # Snapdragon HTP runtime configuration
│
├── onnx/                      # Exported ONNX model
├── qnn/                       # QNN converted model files
│
├── results/                   # Evaluation and inference outputs
│
├── create_model.py            # PyTorch model creation
├── evaluate_imagenet_accuracy.py
│
├── input_batch_list.txt
├── input_batch_phone.txt
├── input_image_list.txt
├── input_list.txt
│
├── input.raw
├── input_image.raw
│
├── dog.jpg                    # Example input image
│
├── requirements.txt
└── README.md
```

---

# Model Architecture

This project uses **MobileNetV4**, a lightweight convolutional neural network designed for **efficient mobile and embedded vision applications**.

Key architectural features include:

* Depthwise separable convolutions
* Inverted residual blocks
* Linear bottlenecks
* Low parameter count and reduced computation

These design principles make MobileNetV2 ideal for **mobile edge AI deployment**.

---

# Technology Stack

The pipeline integrates the following technologies:

* **PyTorch** – model development and export
* **ONNX** – intermediate model representation
* **Qualcomm QNN SDK** – model compilation and runtime
* **Snapdragon AI Hardware** – accelerated on-device inference
* **Python** – preprocessing, evaluation, and automation scripts

---

# Installation

Clone the repository:

```bash
git clone https://github.com/01fe23bcs128/snapdragon-qnn-mobilenetv2.git
cd snapdragon-qnn-mobilenetv2
```

Install required Python dependencies:

```bash
pip install -r requirements.txt
```

---

# Export PyTorch Model to ONNX

The PyTorch model can be exported to ONNX format using:

```bash
python create_model.py
```

The generated ONNX model will be saved in:

```
onnx/
```

---

# Convert ONNX Model to QNN

Using the Qualcomm QNN conversion tools:

```
qnn-onnx-converter \
--input_network mobilenetv2.onnx \
--output_path qnn/
```

This step converts the ONNX model into the **QNN graph representation**.

---

# Compile QNN Model

Compile the converted model into a **shared runtime library for Android (ARM64 architecture)**.

```
qnn-model-lib-generator \
--model qnn/mobilenetv2.cpp \
--output_dir android_build/aarch64-android
```

Output:

```
libmobilenetv4.so
```

This library can be executed using the **QNN runtime on Snapdragon devices**.

---

# Running Inference

Inference requires the input tensor in **RAW format**.

Example workflow:

```
Input Image → Preprocessing → RAW Tensor → QNN Runtime → Model Execution → Predictions
```

Example input file:

```
input_image.raw
```

---

# Evaluation

Model accuracy can be evaluated using:

```bash
python evaluate_imagenet_accuracy.py
```

The evaluation dataset is stored in:

```
dataset_eval/
```

Results are saved in:

```
results/
```

---

# Example Inference

Example input image:

```
dog.jpg
```

Converted into tensor format:

```
input_image.raw
```

Example prediction output:

```
Input Image : dog.jpg
Predicted Class : Golden Retriever
Confidence : 0.92
```

---

# Environment

Development environment used for this project:

```
Python        : 3.10
PyTorch       : 1.13.1
ONNX          : 1.14.0
Operating Sys : Ubuntu 22.04 (WSL)
Target Device : Qualcomm Snapdragon
Runtime       : Qualcomm QNN SDK
```

---

# Technical Contributions

This project demonstrates the following technical components:

* End-to-end **AI model deployment pipeline**
* Conversion from **PyTorch → ONNX → QNN**
* Model compilation for **Snapdragon hardware acceleration**
* Dataset preprocessing and batch inference evaluation
* Edge AI inference pipeline for **mobile and embedded devices**

The repository provides a **reference implementation for deploying neural networks on Qualcomm Snapdragon platforms using QNN**.

---

# Potential Applications

This deployment pipeline can be used for:

* Mobile image classification
* Edge AI computer vision
* Embedded AI systems
* Real-time object recognition
* Snapdragon AI demonstrations

---

# Author

**Aditi Choudhary**

GitHub
https://github.com/01fe23bcs128


---

# License

This project is intended for **research, educational, and experimental purposes related to edge AI deployment**.
