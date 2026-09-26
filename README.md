[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md)

# 德州AI源码｜CFR算法德州扑克机器人与单挑AI引擎

MasterAI 是线上 README 展示的德州扑克博弈 AI 项目，面向 **1v1 Heads-Up** 与项目所述 **1v9** 场景，研究 CFR（反事实遗憾最小化）、博弈论、强化学习、自我博弈、蒙特卡洛采样、神经网络估值与实时决策。

> 仅限学术、算法和技术研究。对战成绩沿用线上 README 的项目方记录；模型版本、评测协议、硬件和可复现性应独立核验。

## 专题导航

- [德州AI源码](https://masterai-top.github.io/TexasHoldem-Poker-AI-HeadsUp-Engine/zh-cn/texas-holdem-ai-source-code.html)
- [CFR算法与德州扑克AI](https://masterai-top.github.io/TexasHoldem-Poker-AI-HeadsUp-Engine/zh-cn/cfr-poker-ai.html)
- [德州机器人与实时决策引擎](https://masterai-top.github.io/TexasHoldem-Poker-AI-HeadsUp-Engine/zh-cn/poker-bot-engine.html)
- [繁體中文](README.zh-TW.md) · [English](README.en.md)

## 线上 README 原有战绩

| 指标 | 项目方公开数据 |
| --- | --- |
| 日期 | 2020-09-22 |
| 对战手牌 | 31,561 手 |
| 百手赢利 | +36.38 BB/100 |
| 对手 | 14 位中国顶级职业选手 |
| 形式 | 一对一、0-100BB |

## 核心技术

| 技术 | 仓库与线上 README 对应内容 |
| --- | --- |
| CFR算法 | `CfrServer` 中的动作树、遗憾值与策略相关模块 |
| 蒙特卡洛采样 | 近似不完全信息博弈中的行动价值 |
| 自我博弈 | `train` 目录中的 Agent、Trainer、GameTree 与任务组件 |
| 手牌与规则 | `Common/SBotInterface` 中的 hand evaluator、card abstraction 与 rule filter |
| 在线服务 | `APGIServer`、CFR 客户端、游戏管理与 Redis 接口 |
| 策略目标 | 以纳什均衡近似和 GTO 研究为目标；可利用度需标准评测 |

## 代码结构

```text
APGIServer/              API 与实时决策服务
CfrServer/               CFR 算法核心
Common/SBotInterface/    手牌评估、抽象、规则与机器人接口
train/                   自我博弈与训练器
roomlogic/               房间和玩家状态逻辑
timeoutlogic/            行动超时逻辑
```

## 实战截图



![MasterAI 德州扑克AI赛事截图 1](https://github.com/user-attachments/assets/8982ce0a-4d9b-4c55-bfb2-ec8228e1a23a)
![MasterAI 德州机器人赛事截图 2](https://github.com/user-attachments/assets/4c5591c7-e59a-4fde-8af9-723243ce0cf1)
![CFR 德州扑克AI对战截图 3](https://github.com/user-attachments/assets/3d473e19-db23-4cf2-a4d2-50d73cb8ab77)
![德州AI源码对战截图 4](https://github.com/user-attachments/assets/3fd8c2d9-8dde-42a9-a82f-1f8677610735)

## 联系

Telegram：[@xuzongbin001](https://t.me/xuzongbin001) · Email：masterai918@gmail.com

![Stars](https://img.shields.io/github/stars/masterai-top/TexasHoldem-Poker-AI-HeadsUp-Engine?style=social)
![Last Commit](https://img.shields.io/github/last-commit/masterai-top/TexasHoldem-Poker-AI-HeadsUp-Engine)
