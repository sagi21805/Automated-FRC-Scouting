from ultralytics import YOLO

# # Load a model
# model = YOLO("yolov8n.yaml")  # build a new model from scratch

# Use the model
# print("start")
# model.train(data="./data-ROBOT.yaml", epochs=50)  # train the model
# metrics = model.val()  # evaluate model performance on the validation set
  
model = YOLO("yolov8n.yaml")

model.train(data="./data-GamePiece.yaml", epochs=100)  # train the model
metrics = model.val()  # evaluate model performance on the validation set