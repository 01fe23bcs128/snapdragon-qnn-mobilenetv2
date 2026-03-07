import os
import numpy as np

RESULTS = "/mnt/c/Users/aditi.ADITI_CHOUDHARY/output_imagenet_100"
RAW_INPUT_LIST = "imagenet_eval/input_list_100.txt"
DATASET_ROOT = "imagenet_eval/imagenette2-160/val"

# ImageNette → ImageNet class index mapping
imagenette_map = {
    "n01440764":0,
    "n02102040":217,
    "n02979186":482,
    "n03000684":491,
    "n03028079":497,
    "n03394916":566,
    "n03417042":569,
    "n03425413":571,
    "n03445777":574,
    "n03888257":701
}

# map image → ground truth class index
image_gt = {}

for folder in os.listdir(DATASET_ROOT):
    folder_path = os.path.join(DATASET_ROOT,folder)
    gt_index = imagenette_map[folder]

    for img in os.listdir(folder_path):
        image_gt[img] = gt_index


with open(RAW_INPUT_LIST) as f:
    raw_files = [x.strip() for x in f.readlines()]

top1_correct = 0
top5_correct = 0
total = 0

for i,raw in enumerate(raw_files):

    img_name = os.path.basename(raw).replace(".raw","")
    gt = image_gt.get(img_name,None)

    if gt is None:
        continue

    output_file = os.path.join(
        RESULTS,
        f"Result_{i}",
        "output.raw"
    )

    logits = np.fromfile(output_file,dtype=np.float32)

    exp = np.exp(logits - np.max(logits))
    prob = exp / exp.sum()

    top5 = prob.argsort()[-5:][::-1]
    top1 = top5[0]

    if top1 == gt:
        top1_correct += 1

    if gt in top5:
        top5_correct += 1

    total += 1


print("\nEvaluation Results")
print("------------------")
print("Total images:",total)
print("Top1 accuracy:",top1_correct/total)
print("Top5 accuracy:",top5_correct/total)
