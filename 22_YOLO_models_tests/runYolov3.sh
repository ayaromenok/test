
CURPATH=`pwd`
cd ~/sdk/dnn/darknet/
./darknet detector test ./cfg/coco.data ./cfg/yolov3.cfg $CURPATH/data/yolov3.weights ./data/dog.jpg -i 0 -thresh 0.25 > $CURPATH/results/v3.txt



