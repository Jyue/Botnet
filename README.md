# Botnet
僅模擬連線，spam、DDOS部分僅是傳字串，無實際攻擊功能。

old>>server.c 和 client.c － 用TCP寫的聊天室

------------------------------------------------------
source資料夾

master_bot.py
- 基本連線，伺服器：freenode.irc.net
- Join channel #testset, botowner: jtlin
- 一開始會有一個Random hash的十個英文字做為Nickname，以便登入
- 自動Ping/Pong，讓bot不會因為timeout而被Freenode IRC server關掉
- 可以從server跟其他clients  receive messege
- 特殊自訂指令:$SPAM、$DDOS (僅傳字串作為模擬之用，無實際功能)
- 以index.html作為GUI介面，每隔一段時間(預設10秒)傳送上線人員之資料到html

slave_bot.py
- 基本上同master_bot.py,差別在不能發送特殊指令，只能接受master bot的指令並執行對應功能(目前僅用字串示意)

index.html
-master的網頁介面


# master使用說明
1. python master_bot.py 開啟master bot
2. 開啟瀏覽器，網址輸入127.0.0.1:8000 ，即可在本地瀏覽器開啟index.html
3. 可在index.html處輸入欲發送給所有slave之訊息
4. 或是直接點按鈕送出特殊指令SPAM、DDOS
