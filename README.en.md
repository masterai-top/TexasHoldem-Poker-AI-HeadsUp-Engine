[简体中文](README.md) | [繁體中文](README.zh-TW.md) | [English](README.en.md)

# Texas Hold'em AI Source Code｜CFR Poker Bot and Heads-Up Engine

MasterAI is the Texas Hold'em game-theory AI project described by the existing online README. It covers CFR, reinforcement learning, self-play, Monte Carlo sampling, neural-network value estimation and real-time decision services for heads-up research and the project's described 1v9 scenario.

> For academic and technical research only. Match results are project-owner records retained from the online README and require independently reproducible evaluation.

## Research scope

- `CfrServer`: action trees, regret values and CFR strategy components.
- `train`: agents, trainer, game tree and self-play tasks.
- `Common/SBotInterface`: hand evaluation, card abstraction, rules and bot interfaces.
- `APGIServer`: API, CFR client, game management and Redis integration.

The online README records a 31,561-hand match against 14 professional players on 2020-09-22 with a reported +36.38 BB/100 result in a heads-up 0-100BB format.

## Screenshots retained from the online README

![MasterAI Texas Holdem AI match 1](https://github.com/user-attachments/assets/8982ce0a-4d9b-4c55-bfb2-ec8228e1a23a)
![MasterAI poker bot match 2](https://github.com/user-attachments/assets/4c5591c7-e59a-4fde-8af9-723243ce0cf1)
![CFR poker AI match 3](https://github.com/user-attachments/assets/3d473e19-db23-4cf2-a4d2-50d73cb8ab77)
![Texas Holdem AI source code match 4](https://github.com/user-attachments/assets/3fd8c2d9-8dde-42a9-a82f-1f8677610735)

Chinese search terms: 德州AI、CFR算法、德州机器人、德州AI源码。Traditional Chinese: 德州AI、CFR演算法、德州機器人、德州AI源碼。
