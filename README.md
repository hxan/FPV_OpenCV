# FPV_OpenCV
FPV_OpenCV is for explorer


笔记本上(接收端)

1.(C++版本)使用脚本

2.(C++版本)直接命令执行 `re 5099 >/dev/null &` re+端口

3.`python`版本执行`python re.py 5099`






工控机上(发送端)

1.(C++版本)使用脚本

2.(C++版本)直接命令执行 `se 192.168.1.104 5099 0 50>/dev/null &`

即`se IP PORT 摄像头号 发送质量`

3.`python`版本执行`python se.py 192.168.1.104 5099 0 50 `





安装过程：

执行`install.sh`脚本即可
