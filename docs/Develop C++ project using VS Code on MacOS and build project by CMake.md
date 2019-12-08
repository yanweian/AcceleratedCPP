# Develop C++ project using VS Code on MacOS and build project by CMake
## 整体环境
- 操作系统：Mac OS
- 编译器：clang/clang++
- 调试器：lldb
- IDE: VS Code
- builder：cmake

## 安装`VS Code`和`cmake`
### VS Code

[vs code 官网](https://code.visualstudio.com)

### cmake
```bash
# 如果没换源，并且没梯子，先进行下一节brew源设置
brew update
brew install cmake
```
### brew 源设置
替换现有上游：
```bash
git -C "$(brew --repo)" remote set-url origin https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/brew.git

git -C "$(brew --repo homebrew/core)" remote set-url origin https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/homebrew-core.git

git -C "$(brew --repo homebrew/cask)" remote set-url origin https://mirrors.tuna.tsinghua.edu.cn/git/homebrew/homebrew-cask.git

brew update
```
复原：
```bash
git -C "$(brew --repo)" remote set-url origin https://github.com/Homebrew/brew.git

git -C "$(brew --repo homebrew/core)" remote set-url origin https://github.com/Homebrew/homebrew-core.git

git -C "$(brew --repo homebrew/cask)" remote set-url origin https://github.com/Homebrew/homebrew-cask.git

brew update
```
替换Homebrew Bottles源:
```bash
# bash 用户
echo 'export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.ustc.edu.cn/homebrew-bottles' >> ~/.bash_profile
source ~/.bash_profile
# zsh用户
echo 'export HOMEBREW_BOTTLE_DOMAIN=https://mirrors.ustc.edu.cn/homebrew-bottles' >> ~/.zshrc
source ~/.zshrc
```

## VS Code 插件

![需要安装的插件](https://user-gold-cdn.xitu.io/2019/12/8/16ee436185d7e0ac?w=1822&h=1458&f=png&s=355619)
附加插件说明：

    - Chinese(Simplified): vscode的中文扩展
    - Markdown *: 编写Readme.md等markdown文件用
    - vscode-icons：图标包
    
## Project 目录结构

![目录结构](https://user-gold-cdn.xitu.io/2019/12/8/16ee43cebe125700?w=720&h=1008&f=png&s=98785)
### 说明
- .vscode：用来保存vscode配置
     - launch.json: 常用来配置程序的启动
     - task.json: 常用来配置程序启动前的编译任务
- build：用来保存执行`cmake`命令所生成的编译所需的文件
    - Makefile: 由`cmake`自动生成，在该目录下执行`make`即可完成项目编译
- include: 头文件目录
- src：源文件目录
- CMakeLists.txt：cmake所需文件
- **注意：build目录中的文件不需要手动创建，我们只需要创建build这个目录就行，其他的交给`cmake`自动创建**
### 项目源码
学习《accelerated c++》过程中写的代码，并学习cmake使用方法，构成的模板项目

项目描述：输入姓名、期中成绩、期末成绩、[平时作业成绩]，按照一定的规则计算其最终成绩（0.2\*midterm+0.4\*final+0.4(平时成绩的中值)）

[github地址](https://github.com/yanweian/CPPLearning/tree/master/组织程序和数据)

## CMakeLists.txt
```cmake
# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project，可以任意指定
project(Project)

# 扫描 src/ 下的所有源文件，并将文件名存入 DIR_SRCS 中
aux_source_directory(src/ DIR_SRCS)

# Add all the source files needed to build the executable
# ${DIR_SRCS}:所有源文件
# main：将生成的可执行文件名
add_executable(main ${DIR_SRCS})

```
上面这个是最简单的 CMakeLists.txt 的例子，随着项目逐渐庞大，需要越来越多的特性，逐步学习

## launch.js

用来执行调试的启动配置文件

```js
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(lldb) launch debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/main",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "lldb",
            "preLaunchTask": "make"
        }
    ]
}
```
### 说明
- "program":可执行文件的位置，对应于cmakelists.txt中生成文件的名字
- "externalConsole":打开外部terminal
- "preLaunchTask": 执行该文件之前需要执行的任务（常为编译过程）

## task.js
用来执行调试前编译的配置文件
```js
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "make",
            "type": "shell",
            "options": {
                "cwd": "${workspaceRoot}/build"
            },
            "command": "make",
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```
上面的代码等价于
```bash
cd build
make
```
说明：其实在执行上面的`make`之前，需要执行下面的命令
```bash
mkdir build
cd build
cmake ..
```
来创建编译项目所需的makefile文件及其他相关文件**上面这步命令我们不需要自己执行**：插件 `cmake tools` 会替我们执行

按键：command+shift+p，在输入框中输入cmake，执行`clean rebuild`

![](https://user-gold-cdn.xitu.io/2019/12/8/16ee4655fed6c7cd?w=1426&h=680&f=png&s=114104)

## 总结
在完成上述所有文件的配置后，按下面的操作即可：
1. `command+shift+p -> cmake:clean rebuild`
2. 执行调试：

![](https://user-gold-cdn.xitu.io/2019/12/8/16ee4688b233331c?w=982&h=724&f=png&s=57008)
说明：这一步具体执行了下面的命令
```bash
cd build
make
./main
```
3. 系统会弹出一个 terminal 窗口，供我们调试
![](https://user-gold-cdn.xitu.io/2019/12/8/16ee46ae39038cf2?w=1810&h=1064&f=png&s=1296252)
