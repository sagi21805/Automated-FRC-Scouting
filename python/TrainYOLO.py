from ultralytics import YOLO

# Load a model
model = YOLO("yolov8n.yaml")  # build a new model from scratch

# Use the model
print("start")
model.train(data="./data-ROBOT.yaml", epochs=30)  # train the model
metrics = model.val()  # evaluate model performance on the validation set
  
