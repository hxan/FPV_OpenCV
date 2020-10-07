# FPV_OpenCV
FPV_OpenCV is for explorer

笔记本上(接收端)
1.使用脚本
2.直接命令执行 `re 5099` re+端口
3.`python`版本执行`python re.py 5099`

工控机上(发送端)
1.使用脚本
2.直接命令执行 `se 192.168.1.104 5099 0 50`
即`se IP PORT 摄像头号 发送质量`
3.`python`版本执行`python se.py 192.168.1.104 5099 0 050 `


