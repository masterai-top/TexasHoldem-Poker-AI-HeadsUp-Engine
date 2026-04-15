# ♠️ MasterAI - 德州扑克最强AI | World-Class Texas Hold'em AI

> **战胜14位中国顶级职业选手 | 每百手赢利36.38大盲 | 基于CFR+GTO的超级AI**

[![Contact](https://img.shields.io/badge/联系-TG%3A%40xuzongbin001-blue)](https://t.me/xuzongbin001)
[![Win Rate](https://img.shields.io/badge/AI胜率-顶级职业选手-red)]()
[![Platform](https://img.shields.io/badge/平台-Linux%20%7C%20Windows-green)]()

---

## 🏆 战绩证明 | Proven Results

> **2020年9月，MasterAI 在与14位中国顶级职业选手的31561手牌对决中，以每百手赢取36.38大盲的优势取胜**

| 指标 | 数据 |
| :--- | :--- |
| 对战手牌数 | 31,561 手 |
| 百手赢利 | +36.38 BB |
| 对手水平 | 14位中国顶级职业选手 |
| 比赛形式 | 一对一有限押注 (0-100BB) |

---

## 🧠 核心技术 | Technology

MasterAI 基于**博弈论(GTO) + 深度学习 + 强化学习**，采用以下前沿技术：

| 技术 | 说明 |
| :--- | :--- |
| **CFR算法** | 虚拟遗憾最小化，计算纳什均衡策略 |
| **蒙特卡洛采样** | 大量MC采样逼近最优行动价值 |
| **神经网络估值** | 离线求解+在线连续重解 |
| **纳什均衡策略** | GTO最优策略，无法被利用 |

### 架构组成

- **离线组件**：求解随机扑克局面，训练神经网络预测每手牌的价值
- **在线组件**：使用连续重解算法，动态选择最优行动

---

## 📁 代码结构
├── APGIServer/ # API服务
├── CfrServer/ # CFR算法核心 (遗憾最小化)
├── Common/ # 公共库
├── Models/ # AI训练模型
└── Proto/ # 协议定义

**语言占比**：C++ 81% | C 18% | 其他 1%

---

## 🎯 适用场景 | Use Cases

| 场景 | 说明 |
| :--- | :--- |
| 🎮 **AI陪玩** | 接入你的德州游戏，提供高难度AI对手 |
| 📚 **学术研究** | CFR、GTO算法的完整实现参考 |
| 🤖 **AI辅助软件** | 实时分析建议，辅助人类决策 |
| 🏢 **俱乐部系统** | 完整德州俱乐部源码（可另购） |

---

## 💰 获取源码 | Contact

我们提供以下产品：

- ✅ MasterAI 1vs1 完整源码 + 训练模型
- ✅ 德州扑克完整游戏源码（俱乐部+联盟+私人局）
- ✅ 德州AI辅助软件

📱 **Telegram：@xuzongbin001**  
📧 **Email：masterai918@gmail.com**

👉 **联系我获取演示视频 + 详细报价**

---

## 📚 相关链接

- [德州扑克完整游戏源码](https://github.com/masterai-top/Texas-game-source-code)
- [AI对战演示站](http://master.deeptexas.ai/aigame/)

---

⭐ Star 这个仓库，支持世界级德州AI的持续进化！

## 📸 实战截图

| AI对战界面 | 胜率曲线 | 技术架构 |
| :---: | :---: | :---: |
MasterAI赛事情况如下 ：
![640](https://github.com/user-attachments/assets/8982ce0a-4d9b-4c55-bfb2-ec8228e1a23a)
![640 (1)](https://github.com/user-attachments/assets/4c5591c7-e59a-4fde-8af9-723243ce0cf1)


 9/1~9/4 首届全明星邀请赛，MasterAI 机器人已战胜顶尖扑克游戏职业高手每百手赢取大盲达到平均36.38的水准，大赢人类职业选手。

![微信图片_20241030105723](https://github.com/user-attachments/assets/3d473e19-db23-4cf2-a4d2-50d73cb8ab77)
![微信图片_20241030103520](https://github.com/user-attachments/assets/3fd8c2d9-8dde-42a9-a82f-1f8677610735)





德州AI，德州扑克AI，德州AI源码，德州AI训练模型，德州AI源码，德州扑克源码，德州俱乐部，德州金币大厅也出，出AI源码和训练模型，德州AI辅助软也出的哦；联系Telegram：@xuzongbin001或E-mail：masterai918@gmail.com
# MasterAI-1.0-1vs1-Limit
mã nguồn game Texas Hold'em
Câu lạc bộ Texas Hold'em, bàn chơi riêng tư, bàn bạn bè, trò chơi poker Texas Hold'em, mã nguồn poker Texas Hold'em, trò chơi poker Texas Hold'em, mã nguồn trò chơi poker Texas Hold'em.

Sản phẩm tinh xảo, chất lượng mã nguồn đáng tin cậy.

Bao gồm nhiều thể loại chơi poker Texas như: SNG, MTT, Texas cổ điển, Pineapple lớn, Short Deck và 7–8 kiểu chơi khác.

Có liên minh, trò chuyện thoại. Mã nguồn Texas, mã nguồn trò chơi Texas Hold'em

Liên hệ qua Telegram: @xuzongbin001

## Introduction

MasterAI is an AI poker dedicated to suport n-play (single- or multi-agent) Texas Hold'em imperfect-informatin games. It has been achieving exceptionally good results by using its propretary algorithm. In September 2020, it defeated 14 top human poker professionals. 
MasterAI 是Master团队在非完美信息博弈中实现的的一种扑克AI，在德州扑克一对一的有限押注已经取得一定成果，MasterAI于2020年9月战胜了中国的14位顶级扑克职业选手。

## Technology

MasterAI is developed by two components: offline component and online component:
* An offline component solves random poker situations (public states along with probability vectors over private hands for both players) and uses them to train a neural network. After training, this neural network can accurately predict the value for each player of holding each possible hand at a given poker situation.

* An online component uses the continuous re-solving algorithm to dynamically select an action for MasterAI to play at each public state during the game. This algorithm solves a depth-limited lookahead using the neural network to estimate values at terminal states.

The MasterAI strategy approximates a Nash Equilibrium, with an approximation error that depends on the neural network error and the solution error of the solver used in continuous re-solving.

## Prerequisites

Running any of the MasterAI code requires [torch](http://torch.ch/).
Torch is only officially supported based on *Linux systems. [This page](https://github.com/torch/torch7/wiki/Windows)
contains suggestions for using torch on a Windows machine

If you would like to personally play against MasterAI, We provide AI models to challeng,[click here](https://master.deeptexas.ai/aigame/).

## Contact us

The Master team is constantly exploring the innovation of AI algorithm, and hoping that like-minded technical experts from all over the world can communicate and exchange here, or join us to make MasterAI bigger and stronger together. Please feel free to contact us at Telegram：@alibaba401


MasterAI，于2020年9月 战胜14位中国顶级职业德扑高手

MasterAI 是Master团队在非完美信息博弈中实现的的一种扑克AI，在德州扑克一对一的有限押注（0~100BB）已经取得一定成果，MasterAI于2020年9月战胜了中国的14位顶级扑克职业选手；在与国内14位顶尖牌手激烈角逐31561手牌后，MasterAI 最终以23,562总计分牌，每百手赢取36.38个大盲的优势取胜。MasterAI 基于深度学习，强化学习和博弈论，采用Nash纳什均衡的对战策略，通过大量MC蒙特卡洛采样来计算CFR (虚拟遗憾最小化)的值域或频域作为行动Value，不断探索和选取GTO最优策略，形成智能分析和决策。
        
MasterAI赛事情况如下 ：
![640](https://github.com/user-attachments/assets/8982ce0a-4d9b-4c55-bfb2-ec8228e1a23a)
![640 (1)](https://github.com/user-attachments/assets/4c5591c7-e59a-4fde-8af9-723243ce0cf1)


 9/1~9/4 首届全明星邀请赛，MasterAI 机器人已战胜顶尖扑克游戏职业高手每百手赢取大盲达到平均36.38的水准，大赢人类职业选手。

![微信图片_20241030105723](https://github.com/user-attachments/assets/3d473e19-db23-4cf2-a4d2-50d73cb8ab77)
![微信图片_20241030103520](https://github.com/user-attachments/assets/3fd8c2d9-8dde-42a9-a82f-1f8677610735)


有对Master AI  1对1 训练模式和核心算法代码感兴趣或者意向购买源码者可以联系：Telegram：@xuzongbin001



        
