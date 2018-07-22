# 🍺 keymap 🍺
QMKのkeymap個人設定

https://github.com/qmk/qmk_firmware

## 💪 特徴 💪 
- 親指モディファイをサポート
- ime 切り替え頻度を減らす

---

## 🚀 機能 🚀
### 🗾ime 自動切り替え
記号、数値、shift+英字 send時にime off

### 👍ワンショットモディファイ
shift/space の場合

`one_shot_modifiers`で設定
> 動作例 2, 動作例 3を同時に実現している点がポイント

#### 動作例 1
1. shift down
1. shift up

send space 

#### 動作例 2
1. shift hold
1. shift up

send 無し

#### 動作例 3
1. shift down
1. a down
1. shift up 
1. a up

send  A 
> 先にshiftをupしてもAが送信

### 🤘同時押しワンショットモディファイ
shift + cmd /space の場合

`simultaneously_one_shot_modifiers`で設定

#### 動作例 1
shift と cmd 同時down
shift と cmd 同時up

space send

### 🍔ユーザモディファイ
> ワンショットモディファイのレイヤー版

## 🐳 ビルド手順 🐳

### 共通
```
git clone https://github.com/qmk/qmk_firmware
git clone https://github.com/baronTommy/keymap
cd qmk_firmware
```

### ⌨ kinesis
https://github.com/qmk/qmk_firmware/tree/master/keyboards/kinesis/stapelberg
```
cp -r ../keymap/kinesis keyboards
docker run -e keymap=my-keymap -e keyboard=kinesis --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
```

### ⌨ dactyl
https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/dactyl
```
cp -r ../keymap/handwired/dactyl/keymaps/my-keymap keyboards/handwired/dactyl/keymaps
docker run -e keymap=my-keymap -e keyboard=handwired/dactyl --rm -v $('pwd'):/qmk:rw edasque/qmk_firmware
```

---
## 🐶 TODO 🐶
- module化したいが、c言語が良くわからん
- c言語らしいく書けて無い箇所ががある。つまり、c言語が良くわからん


---
## kinesis

## dactyl
![dactyl](https://github.com/baronTommy/keymap/blob/master/doc/dactyl.jpg "dactyl")
