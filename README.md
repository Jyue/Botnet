# Botnet
still need update

------------------------------------------------------


client.py 目前功能：
- 基本連線
- Join channel #testset
- 一開始會有Nickname，以便登入
- Ping/Pong，讓client因為timeout所以被server關掉
- 可以從server跟其他clients  receive messege



- 可以先用這個充當server：　　https://kiwiirc.com/client/irc.freenode.net/
- 未完成，要等server能傳特殊指令給client才能繼續做下去 

client.py 獨立於server之待完成功能：
- 可以讀keyboard and 傳訊息給server
- Unique Nickname created by hash
