gst-launch-1.0 rkisp device=/dev/video4 sensor-id=5 io-mode=4 path-iqf=/etc/cam_iq/rk-ov4689.xml ! video/x-raw,format=NV12,width=1280,height=720,framerate=30/1 ! rkximagesink
