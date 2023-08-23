# 8bitsBMP_CipherToPlainText
###### tags: `C LANGUAGE`

此程式專案為讀取8bits BMP影像中的檔案格式之Hex數值，轉換成Dex並輸出成txt檔。
不引入現有的函式庫，根據BMP檔案格式中的各種欄位去定義出datastruture，幫助理解BMP format的運作與各個欄位之數值。

===

專案運作方式：
---
1. 讀取IPCoefficient.txt內的四個欄位所需之檔名or數值
2. 開啟對應之BMP影像，讀取BMP內部4個區塊的Hex數值，並轉換成Dex
3. 將轉換後之Dex數值輸出至.txt中
