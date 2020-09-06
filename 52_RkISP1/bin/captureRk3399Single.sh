#rkimagesink required io-mode=4 and work correctly only with sinle camera(but faster)
#glimagesink - for dual cam(but with delay)

stop-gst-camera.sh

FNAME=$(date +"%Y_%m_%d__%H_%M_%S")

# 0.. 3..4..5
DBG_LEVEL=3
BUFFERS=5
gst-launch-1.0 rkisp device=/dev/video0 io-mode=4 path-iqf=../cam_iq/ov4689_0.2.5.xml --gst-debug-level=$DBG_LEVEL num-buffers=$BUFFERS ! video/x-raw,format=NV12,width=640,height=360 ! jpegenc ! multifilesink location=./out/imageL_$FNAME.jpg &
sleep 3
stop-gst-camera.sh
