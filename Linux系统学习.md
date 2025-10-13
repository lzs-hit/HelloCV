<h3 id="dZwDV">1.linux的安装</h3>
> 我采用的方式是安装VMware虚拟机搭载Ubuntu22.04
>

VMware和Ubuntu的安装包都是直接从网上的教程里下载的，下面是配置的过程：

1.先配置变量，将bin放进Path里

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760259785211-00b0182d-7930-4ae0-9303-af60e08d65e5.png)

2.然后点击新建虚拟机，选择自定义![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760259926239-6adafd3a-ea35-4095-b9ea-4ea7ab9aa3f3.png)

3.然后将虚拟机放进我创建的文件夹里（放在D盘不要做C盘战神（））![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760259986111-7aa76f41-4dd6-42fe-8794-76b62f672400.png)

4.这里看了一下任务管理器，根据电脑情况（电脑配置较低，不过马上就要换了）选择4+2（查了下ds应该不耽误使用）![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760260137175-b26701f9-0222-4ad9-a7b9-1ccb899a1064.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760260074641-93c98bd6-5e71-4cde-b928-3f275627601f.png)

5.这里是运行内存吧，拉到最大也只有6.1g（依旧是老电脑的问题），我参考的教程有27g可以用，不过我看他也选了4g，我选6.1估计也够用了![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760260308768-1044d726-66de-4a61-afdf-c0040acff28c.png)

6.硬盘先选50，看学长在群里说以后需要100以上，等我换电脑了再改成100的![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760260552559-e6d25674-1624-4a32-8654-6680fe42d16a.png)

之后就是指定磁盘文件，直接选择我在D盘创建那个，这样虚拟机就安装完成了

7.下面就是安装操作系统，过程比较简单

首先点击编辑虚拟机，把我下好的ubuntu22.04放在这里的ISO映像文件里

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760261118367-c074799f-2fad-4365-bbdc-e058a96f6298.png)

然后打开虚拟机，设置好语言和账户就完成了

**遇到的问题和疑虑以及我是怎么解决的：**1.刚开始误装了24.04，再次阅读要求时发现装错，遂在群里询问是否需要重装，然后潘苏昊学长和25级的深沉羊学长（？）进行了解答，指出只有22.04可以装ros2 humble，遂重装

2.因为已经确定了双十一要换电脑,且换电脑后准备装双系统，担心自己在VMware上面做的工作不能保存，遂询问ds。好像继续使用虚拟机的话是可以直接迁移的，但装双系统就比较麻烦了，只能慢慢将文件通过u盘转移到新的Ubuntu上。有很多工作可能需要重新做，希望不要太麻烦![](https://cdn.nlark.com/yuque/0/2025/jpeg/61267643/1760262478443-c1fa2df8-7423-4061-bd3c-2ab70e57df7b.jpeg)![](https://cdn.nlark.com/yuque/0/2025/jpeg/61267643/1760262491640-c6f3b11b-7b64-428d-b2a5-bcc3e2e8b2fb.jpeg)![](https://cdn.nlark.com/yuque/0/2025/jpeg/61267643/1760262529061-12566788-fc1a-4dca-8b85-fb8e13765183.jpeg)![](https://cdn.nlark.com/yuque/0/2025/jpeg/61267643/1760262537477-a1e53b5b-7a6a-4d42-adc5-ab5c68fcef13.jpeg)

<h3 id="ZgiDm">2.终端命令</h3>
> 参考资料：朱梓昕学长的视频，周任务文档里的两个教程，B站，deepseek
>

<h4 id="fatpQ">1.软件安装</h4>
在linux中安装软件有多种方法，我主要利用ds学习了apt<font style="color:rgb(97, 102, 107);">（Advanced Package Tool）</font>和snap

想要理解两者的区别，并能做到对某个具体软件选择合适的方法，我们必须理解沙盒的概念。**<font style="color:rgb(15, 17, 21);">沙盒</font>**<font style="color:rgb(15, 17, 21);">是一种安全机制，它将</font>**<font style="color:rgb(15, 17, 21);">一个程序（应用）与系统的其他部分隔离开来</font>**<font style="color:rgb(15, 17, 21);">，限制其能够访问的资源（如文件、网络、硬件设备等）。</font>

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760353611146-7344a097-7857-4c4b-a75e-3602586bef26.png)

也就是说，沙盒将应用所需的所有文件都打包到一起，只通过受到严格限制的权限连接外部。如果两个应用具有一个相同的文件，这个文件会分别出现在两个沙盒中而不会被共用。因为以上特点，沙盒应用具有较高的安全性、稳定性和隐私性，某个应用遭到攻击或崩溃时不会影响到系统中的其他应用，沙盒应用也无法随意读取你的私人数据。因此，大部分网址和应用商店中的应用都是沙盒应用。当然，沙盒也有它的缺点，，比如需要更多的系统文件减缓了运行效率，给一些需要深度集成的应用带来兼容性问题等。

apt是linux传统的软件包安装方式，是非沙盒的，应用直接访问系统库，拥有更加透明的权限模型；snap则是Ubuntu的母公司响应沙盒化趋势发行的自包含软件管理方式。作为开发学习者，我想我应该主要使用apt安装工程软件

它们还有一些其它区别：apt需要手动更新，snap则会自动更新；apt安装的应用启动速度更快

**基本语法（以安装vscode为例）**

```plain
sudo snap install code
```

```plain
sudo apt update #检查更新
sudo apt install code
```

当然，根据应用的特性也会有一些差别，比如vscode需要不受限制的系统访问权限，所以snap必须在后面加上--classic命令，而apt直接从官方库下载下来的是十分陈旧的版本，想要最新的版本需要添加微软官方源，所以正确的版本应该是：

```plain
sudo snap install code --classic
```

```plain
# 1. 下载并信任微软的GPG密钥
wget -qO- https://packages.microsoft.com/keys/microsoft.asc | gpg --dearmor > packages.microsoft.gpg
sudo install -o root -g root -m 644 packages.microsoft.gpg /etc/apt/trusted.gpg.d/

# 2. 添加微软软件仓库
sudo sh -c 'echo "deb [arch=amd64,arm64,armhf signed-by=/etc/apt/trusted.gpg.d/packages.microsoft.gpg] https://packages.microsoft.com/repos/code stable main" > /etc/apt/sources.list.d/vscode.list'

# 3. 更新并安装
sudo apt update
sudo apt install code

# 4. 以后想更新时，需要记得手动运行
sudo apt update #检查更新 && sudo apt upgrade #更新
```

按照学长视频中的方式，我用apt指令成功安装了vim

<h4 id="p2LxZ">2.文件管理</h4>
<h5 id="HJFRR">1.一些基本用法</h5>
mkdir创建文件夹

cd进入/退出到不同位置

pwd获取当前地址

ls显示当前目录下的成员

touch创建文件

rm删除文件

rm -r删除文件夹（-r是递归的意思）

以及tab自动补全，↑↓可回溯历史命令等（感觉跟git和powershell的用法差不多，只不过git不用tab就能自动补全）

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760281064457-a47ef9b7-971a-413d-930b-00c953b82874.png)

<h5 id="EYbKX">2.cp&mv</h5>
cp是一种复制操作，语法为cp+[选项]+被复制名+复制后的重命名（仍然在当前地址）/目标目录，其中最常用的选项是-r，它的作用是复制整个目录，比如在这里我将backupdir中的456及其中的learn.txt和LEARN.txt整个复制到了789里

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760329871920-ca1d9d5e-6aba-42ba-8069-90626880d015.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760329872112-93fab5e5-f40d-4283-9c1b-d94332511077.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760329872292-e881c2f9-fb01-40ad-9fa4-b9d5d7ce4eab.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760329872250-9d083566-625e-441a-8df5-23217fdc7f2e.png)

可以看到我这里出了很多错误：

1.当我要复制/home/lizhengshuo/123中的learn.txt时，我最开始直接在/home/lizhengshuo里进行操作，发现找不到这个文件，进入123中就可以正常复制了，看来cp操作必须进入最接近复制对象的目录里才可以进行

2.若目标地址不在当前目录下面，必须要输入目标地址的全称，比如将123中的文件cp到同级的456中，直接写456/是找不到这个目录的

3.地址一定要加/，否则将会被识别为新的文件名

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760329871901-f818408f-b5b2-4a46-ae5b-a5976bc90e15.png)

ds告诉我，最好每次操作都加入-i选项，进入interactive模式，如果文件已经存在，它会让你确认是否要覆盖（如上图），这会避免错误覆盖导致原文件丢失，我认为这很实用

附一些常用选项：

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760330978121-7b147970-8d94-490b-94a4-054117becfc5.png)

（这个-u看起来非常实用！）



mv是移动（move）操作，它相当于剪切+粘贴，也可以用来重命名

基本语法：

mv [选项] 源文件 目标文件

mv [选项] 源文件... 目标目录

mv的基本用法和cp差不多，需要注意的是，重命名目录时不需要-r

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760332678077-9155184f-176f-436e-b438-ab2119e86c53.png)

常用选项：

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760332713509-bd6f44ca-5d24-49d2-b2b0-9d9677195abd.png)

<h4 id="TUqDP">3.权限管理</h4>
<h5 id="OGweZ">1.ls -l与权限位</h5>
ls与上面文件管理中相同，显示出目录内容，而-l是长格式的内容，可将目录中对象的信息完整的显示出来

```plain
-rwxr-xr-- 1 user group 1234 Dec 5 12:34 example.txt
```

其中包括：

1.权限位：在linux中，用户分为三种：<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">文件所有者（Owner）、用户组（Group）、其它用户（Other Users），分别用u、g、o。a表示所有用户。用户对文件的权限也有三种：读（r），写（w），操作（x）。权限位就是“示例”的最前面的字符串0/000/000/000，表示不同用户对这个文件的权限，其中第一个字符代表文件类型，第2、5、8分别表示u、g、o的读权限（r表示有权限，-表示无权限，其余同理），3、6、9为写权限，4、7、10为执行权限</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">2.硬链接数（1）：指向该文件的硬链接数量</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">3.属主（alice）：文件的所有者用户</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">4.属组（developers）：文件所属的用户组</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">5.大小（2048）：文件大小（字节）</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">6.最后修改时间（Dec 5 10:30）：最后修改的日期和时间</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">7.文件名（my_script.sh）：文件或目录名</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">如果想要单看某一文件，只需在后面加上文件名，但是注意如果要查看某个目录，则要使用 ls -ld，否则将查看目录里面的文件</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">注意，ls -l是不显示隐藏文件和当前位置之前的内容，要想显示全部内容，还可以使用它的“加强版”ls -alF（别名 ll）</font>![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760360659944-451a9a67-4400-4bc8-b812-cd5a923aa9d6.png)

<h5 id="AxuCW">2.chmod命令</h5>
chmod<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">是控制用户对文件的权限的命令</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">修改权限的语法为chmod [选项] 权限模式 文件...，若单纯修改权限，选项可忽略，权限模式格式为[u/g/o/a][+/-/=][r/w/x]（+/-表示要添加/删除哪个权限，=直接选择开启哪些权限）,此外也可通过三位8进制数来表示，三位分别表示u/g/o的权限，其中r=4，w=2，x=1，这样每种权限组合就有唯一的数值对应:</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">e.g. chmod a=rwx …=chmod 777 …</font>

<font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">通过选项能够实现一些其他功能，常用选项：</font>

+ <font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">-c : 若该文件权限确实已经更改，才显示其更改动作</font>
+ <font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">-f : 若该文件权限无法被更改也不要显示错误讯息</font>
+ <font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">-v : 显示权限变更的详细资料</font>
+ <font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">-R : 对目前目录下的所有文件与子目录进行相同的权限变更(即以递归的方式逐个变更)</font>
+ <font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">--help : 显示辅助说明</font>
+ <font style="color:rgb(51, 51, 51);background-color:rgb(250, 252, 253);">--version : 显示版本</font>

注意-c和-v的区别，-c可打印权限的变化，但如果权限没有变化，则无输出，但-v不管权限变没变都可打印出操作的结果![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760358258024-3a1474e4-ab76-41a1-b0d9-8ea8a9228f13.png)

在B站学习相关内容时看到一个很好的思维导图，贴在这![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760286820383-aa032aac-7528-4312-8a53-ed5e5c803894.png)

<h5 id="bRs1H">3.chown</h5>
即change owner，用来改变属主和属组

基本语法：

```plain
sudo chown [新属主] [文件名] #改变属主
sudo chown [新属主]:[新属组] [文件名] #改变属主和属组
```

注意，要想改变目录中所有文件的属主，则需在目录名前加递归选项-R，否则只改变文件夹的属主

一定要记得加sudo！![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760362311826-67b146ad-56b8-4afc-bd07-7286bce4083e.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760362312051-8812c170-16e7-4c07-8565-b99cc0057253.png)

<h4 id="ZGOv9">4.进程控制</h4>
_（注：这些内容目前不太敢实操，主要通过询问ds进行初步的理论学习）_

<h5 id="UuBgO">1.什么是进程？</h5>
首先我们需要了解什么是进程。简单来说，进程就是正在执行的程序，在终端中，我们可以输入ps查看当前终端中正在执行的进程，输入ps aux查看所有进程，输入ps aux | grep xxx则可以查看特定进程![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760367643147-38c14359-acc7-4819-9f60-8c5afa819a6f.png)

```plain
user     1234  0.5  2.1 1023456 78900 ?  Sl   10:30   1:23 firefox
↑        ↑     ↑    ↑   ↑       ↑       ↑  ↑    ↑       ↑   ↑
用户名   PID  CPU 内存  虚拟内存 物理内存 状态 启动时间 运行时间 命令
```

其中PID是该进程的身份信息![僵尸进程：已经终止，不占用CPU和内存的进程，但会占用一个PID](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760368685387-6e9fdbb0-59de-4b7f-b500-cb69e36785e1.png)

<h5 id="sExDy">2.kill</h5>
kill可以给进程发送信号，通常用来终止进程

| <font style="color:rgb(15, 17, 21);">信号编号</font> | <font style="color:rgb(15, 17, 21);">信号名</font> | <font style="color:rgb(15, 17, 21);">作用</font> | <font style="color:rgb(15, 17, 21);">使用场景</font> |
| --- | --- | --- | --- |
| **<font style="color:rgb(15, 17, 21);">1</font>** | `<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">SIGHUP</font>` | <font style="color:rgb(15, 17, 21);">挂起</font> | <font style="color:rgb(15, 17, 21);">让进程重新读取配置文件</font> |
| **<font style="color:rgb(15, 17, 21);">2</font>** | `<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">SIGINT</font>` | <font style="color:rgb(15, 17, 21);">中断</font> | <font style="color:rgb(15, 17, 21);">相当于按 Ctrl+C</font> |
| **<font style="color:rgb(15, 17, 21);">9</font>** | `<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">SIGKILL</font>` | **<font style="color:rgb(15, 17, 21);">强制终止</font>** | <font style="color:rgb(15, 17, 21);">立即杀死进程，无法被捕获或忽略</font> |
| **<font style="color:rgb(15, 17, 21);">15</font>** | `<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">SIGTERM</font>` | **<font style="color:rgb(15, 17, 21);">优雅终止</font>** | <font style="color:rgb(15, 17, 21);">默认信号，让进程清理后退出</font> |
| **<font style="color:rgb(15, 17, 21);">18</font>** | `<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">SIGCONT</font>` | <font style="color:rgb(15, 17, 21);">继续</font> | <font style="color:rgb(15, 17, 21);">继续运行已停止的进程</font> |
| **<font style="color:rgb(15, 17, 21);">19</font>** | `<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">SIGSTOP</font>` | <font style="color:rgb(15, 17, 21);">暂停</font> | <font style="color:rgb(15, 17, 21);">暂停进程执行（不可被捕获）</font> |


```plain
# kill（识别PID，精准终止进程）
kill 1234 #没有信号默认为-SIGTERM
kill -9 1234 #使用信号编号+PID
kill -SIGKILL 1234 #使用信号名+PID

# killall（只识别进程名，且要求与命令行完全一致）
# pkill（识别完整命令行，只要有即终止） 
# e.g
# PID    COMMAND
# 1234   python web_server.py
# 5678   python worker.py  
# 9012   python3 data_processor.py
# 3456   /usr/bin/python backup.py
killall python #杀死1234、5678，因为它们的进程名是python
pkill python #杀死全部，因为每个命令行中都包含python
```

```plain
# 1. 先查找进程PID
ps aux | grep python
# 输出：user     1234  0.0  0.1  12345  6789 pts/0    S+   10:00   0:00 python app.py

# 2. 优雅终止
kill 1234

# 3. 如果上面不生效，强制终止
kill -9 1234

# 或者一步完成
pkill -f "python app.py"
```

<h5 id="gmZix">3.top</h5>
<font style="color:rgb(15, 17, 21);">可实时显示系统进程状态和资源使用情况</font>

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760371334075-7056561f-0af3-4a1e-9e77-6ede46dce60b.png)

默认按CPU排序，按Shift+M改为按内存使用率排序，按Shift+P改为按进程ID排序，按q可退出

top中有一些常用快捷键：

+ **<font style="color:rgb(15, 17, 21);">h</font>**<font style="color:rgb(15, 17, 21);">：显示帮助</font>
+ **<font style="color:rgb(15, 17, 21);">k</font>**<font style="color:rgb(15, 17, 21);">：杀死进程（会提示输入PID）</font>
+ **<font style="color:rgb(15, 17, 21);">r</font>**<font style="color:rgb(15, 17, 21);">：调整进程优先级（renice）</font>
+ **<font style="color:rgb(15, 17, 21);">1</font>**<font style="color:rgb(15, 17, 21);">：显示每个CPU核心的使用情况</font>
+ **<font style="color:rgb(15, 17, 21);">u</font>**<font style="color:rgb(15, 17, 21);">：只显示指定用户的进程</font>

<h3 id="ljAvI">3.文件系统</h3>
> 主要通过ds来学习
>

一个与Windows相似的树状文件系统

<h5 id="mkSgI">1. 根目录（/）</h5>
根目录是文件系统的最顶层，所有其他目录都在根目录之下

<h5 id="LKObB">2./home（用户的个人文件夹）</h5>
简记为~（~=/home/lizhengshuo）

<font style="color:rgb(15, 17, 21);">用来存放用户的文档、下载、配置等个人文件</font>

<h5 id="sETr0"><font style="color:rgb(15, 17, 21);">3./etc（配置文件目录）</font></h5>
用来存放系统和服务的配置文件，记录系统运行的规则

```plain
/etc/passwd          # 用户账户信息
/etc/group           # 用户组信息
/etc/hosts           # 主机名映射
/etc/nginx/nginx.conf # Nginx配置
```

<h5 id="CbuNV">4./var（存放经常变化的文件）</h5>
<font style="color:rgb(15, 17, 21);">用来存放经常变化的文件，相当于活动记录中心</font>

```plain
# 重要的子目录
/var/log/           # 系统日志文件
/var/www/           # 网站文件（常见）
/var/lib/           # 程序的数据文件
/var/tmp/           # 临时文件

# 查看系统日志
ls /var/log
```

<h5 id="e04yW">5.其他重要目录</h5>
| <font style="color:rgb(15, 17, 21);">目录</font> | <font style="color:rgb(15, 17, 21);">作用</font> |
| --- | --- |
| `**<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">/bin</font>**` | <font style="color:rgb(15, 17, 21);">基本命令二进制文件</font> |
| `**<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">/usr</font>**` | <font style="color:rgb(15, 17, 21);">用户程序和文档</font> |
| `**<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">/tmp</font>**` | <font style="color:rgb(15, 17, 21);">临时文件</font> |
| `**<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">/opt</font>**` | <font style="color:rgb(15, 17, 21);">第三方软件</font> |
| `**<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">/boot</font>**` | <font style="color:rgb(15, 17, 21);">启动文件</font> |
| `**<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">/dev</font>**` | <font style="color:rgb(15, 17, 21);">设备文件</font> |


<h3 id="E3dRr">4.网络配置</h3>
由于我用的是虚拟机，VMware已经通过DHCP自动获取了网络配置，不需要我动手了

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760375595186-e410deef-934a-472b-8836-cf9a44ca47b2.png)![验证网络配置是否正常](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760375615937-e4ea718f-4499-421c-950b-3796b4907b42.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760377709077-4246fbc0-947f-433d-a6c7-3bbb9da474dc.png)

然后安装了nginx，打开Firefox一切正常

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760377838735-f0cb4d5b-5b81-4e6e-9bf6-37dc3cb90449.png)

<h3 id="QKQLK">5.基础服务管理（systemd）</h3>
<h5 id="vj742">1.基本信息</h5>
![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760373464730-98f24b23-0c6d-499d-9e10-c1e0140d8533.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760377970223-24bfd5a1-f0c9-4b53-a3c6-13b5d6da8f01.png)

<h5 id="XMgBS">2.服务状态管理</h5>
```plain
# 启动服务
sudo systemctl start service_name

# 停止服务
sudo systemctl stop service_name

# 重启服务
sudo systemctl restart service_name

# 重新加载配置（不重启服务）
sudo systemctl reload service_name

# 查看服务状态
systemctl status service_name

# 检查服务是否在运行
systemctl is-active service_name
```

<h5 id="FP2zX">3.开机自启管理</h5>
```plain
# 启用开机自启
sudo systemctl enable service_name

# 禁用开机自启
sudo systemctl disable service_name

# 检查是否启用开机自启
systemctl is-enabled service_name
```

<h5 id="xVEL9">4.服务查看和监控</h5>
```plain
# 查看所有已启动的服务
systemctl list-units --type=service

# 查看所有服务（包括未运行的）
systemctl list-units --type=service --all

# 查看失败的服务
systemctl --failed

# 查看服务的依赖关系
systemctl list-dependencies service_name
```

<h5 id="fUCkC"><font style="color:rgb(15, 17, 21);">5.服务文件位置</font></h5>
```plain
/usr/lib/systemd/system/    # 系统安装的服务
/etc/systemd/system/        # 用户自定义的服务
```

```plain
# 查看 nginx 的服务配置
systemctl cat nginx

# 或者直接查看文件
cat /usr/lib/systemd/system/nginx.service
```

相关的操作在上面的网络配置中已经练习过不少

<h3 id="MKhNy">6.vim编辑器</h3>
> 主要参考韩明顺老师的视频教程
>

vi是linux内置的文本编辑器，vim是vi的加强版，具有程序编辑的能力，可以用不同的颜色来标记程序![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760378555651-99f478ab-d26a-4fe7-985b-1be5a74bf432.png)

下面我们来进行实战：

在终端输入vim hello.cpp，按下回车，我们就进入了一个c++的编译环境中，然后输入i进入到插入模式

![依旧helloworld](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760378983940-c9836447-e5b7-42ff-9f21-960f68f266a4.png)

我们编写好了一个程序，然后按esc回到正常模式，输入一个：进入命令行模式，然后输入wq（写入并退出！还有其他快捷键）按下回车

我们用ls查看，可以发现这个cpp文件就建立好了

再次输入vim hello.cpp就可以重新回到刚才编辑的界面![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760379547274-0dc06662-0000-46b7-a700-d984f0a19110.png)

![q是正常退出，有未保存修改会阻止退出；q！会强制退出，不保存修改](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760379745148-9bc2c076-2769-453e-ae3c-bdafe8dcb1ba.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760380791757-201709f7-39e3-4199-93fa-b58ff0938445.png)![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760380956612-dfbc1a2c-783d-4e9d-ba72-73aa3d43722d.png)

<h3 id="d35E9">7.常用命令行</h3>
<h5 id="MoyUO">1.tmux</h5>
<font style="color:rgb(15, 17, 21);">tmux可以在一个终端窗口中管理多个终端会话，使得用户即使断开连接也不会丢失工作进度</font>![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760382173018-a50a3422-3211-4376-869a-1d8451f83130.png)

<font style="color:rgb(15, 17, 21);">通过tmux new -s mysession来发起一个新的会话</font>

<font style="color:rgb(15, 17, 21);">所有 tmux 命令都需要先按 Ctrl + b，然后按命令键</font>

```plain
Ctrl + b, d          # 分离会话（会话在后台继续运行）
tmux attach          # 重新连接会话
tmux ls              # 列出所有会话
tmux kill-session -t name  # 杀死会话
Ctrl + b, c          # 创建新窗口
Ctrl + b, n          # 下一个窗口
Ctrl + b, p          # 上一个窗口
Ctrl + b, 数字       # 切换到指定编号窗口
Ctrl + b, &          # 关闭当前窗口
Ctrl + b, %          # 水平分割窗格
Ctrl + b, "          # 垂直分割窗格
Ctrl + b, 方向键     # 切换窗格
Ctrl + b, x          # 关闭当前窗格
Ctrl + b, z          # 最大化/恢复当前窗格
```

![下载tmux和一两次简单的尝试](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760382084352-8917f220-058a-4e94-b50b-daa255e0ae6a.png)



<h5 id="ma4Od">2.grep</h5>
<font style="color:rgb(15, 17, 21);">可以在文件中搜索指定的文本模式</font>

```plain
# 基本语法
grep [选项] "搜索模式" 文件名          # 搜索包含"error"的行

# 基本搜索
grep "error" logfile.txt          # 搜索包含"error"的行

# 常用选项
grep -i "error" file.txt          # 忽略大小写
grep -n "error" file.txt          # 显示行号
grep -v "success" file.txt        # 反向搜索（不包含的行）
grep -r "function" /path/to/dir   # 递归搜索目录
grep -c "pattern" file.txt        # 统计匹配行数
grep -A 3 "error" file.txt        # 显示匹配行及后3行
grep -B 2 "error" file.txt        # 显示匹配行及前2行
```

<h5 id="g08mC">3.sed</h5>
<font style="color:rgb(15, 17, 21);">用于对文本进行流式编辑（查找、替换、删除等）</font>

```plain
#基本语法
sed '命令' 文件名

# 替换文本
sed 's/old/new/g' file.txt              # 全局替换
sed 's/old/new/' file.txt               # 每行只替换第一个
sed 's/old/new/2' file.txt              # 每行替换第二个

# 删除行
sed '5d' file.txt                       # 删除第5行
sed '1,3d' file.txt                     # 删除1-3行
sed '/pattern/d' file.txt               # 删除匹配行

# 打印特定行
sed -n '10p' file.txt                   # 只打印第10行
sed -n '10,20p' file.txt                # 打印10-20行

# 原地编辑（直接修改文件）
sed -i 's/old/new/g' file.txt
```

<h5 id="AdqDk">4.awk</h5>
一种文本分析工具

基本语法：

awk '模式 { 动作 }' 文件名

![](https://cdn.nlark.com/yuque/0/2025/png/61267643/1760382739775-e1f6c956-2188-477e-b042-390de11c484b.png)

```plain
# 打印特定列
awk '{print $1}' file.txt               # 打印第一列
awk '{print $1, $3}' file.txt           # 打印第1和第3列

# 设置分隔符
awk -F',' '{print $2}' data.csv         # 使用逗号分隔
awk -F'[ :]' '{print $1, $3}' file.txt  # 使用空格或冒号分隔

# 条件过滤
awk '$3 > 100 {print $1, $3}' data.txt  # 第三列大于100的行
awk '/error/ {print NR, $0}' file.txt   # 包含error的行及行号

# 计算统计
awk '{sum += $1} END {print sum}' data.txt      # 求和
awk '{count++} END {print count}' file.txt      # 行数统计
```

<h2 id="eQV68">思考</h2>
> 有什么想法或心得体会，都可以拿出来分享下。
>





