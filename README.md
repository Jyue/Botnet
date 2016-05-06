# Botnet
still need update

old>>server.c 和 client.c － 用TCP寫的聊天室

------------------------------------------------------

master_bot.py
- 基本連線
- Join channel #testset
- 一開始會有一個Random hash的十個英文字做Nickname，以便登入
- 自動Ping/Pong，讓bot不會因為timeout所以被server關掉
- 可以從server跟其他clients  receive messege
- 特殊自訂指令:$SPAM、$DDOS (目前僅有傳字串，無實際功能)

slave_bot.py
- 基本上同master_bot.py,差別在不能發送特殊指令，只能接受master bot的指令並執行對應功能(目前僅用字串示意)

master_control_panel.php
-類似master的螢幕
