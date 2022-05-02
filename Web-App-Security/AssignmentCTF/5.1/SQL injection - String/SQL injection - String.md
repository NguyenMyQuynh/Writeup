
# Write up challenge SQL injection - String

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/SQL-injection-String)<br>

Truy cập challenge ta thấy gồm 3 trang Home | Search | Login

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<br> Sau khi test bằng cách nhập `1'` vào ô Recherche trong trang Search em thấy rằng lỗi SQL injection 
 xuất hiện tại đây

<img src="./img/2.png" alt="normal_acc_TRAbID"/> 

Vậy là ta đã biết trang này sử dụng database là SQLite3.
<br> Đầu tiên sử dụng lệnh: `1' order by 1--` để kiểm tra số cột cho phép. 

Tăng dần lên đến `1' order by 3--` thì bị lỗi 

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

Vậy là database này có 2 cột. Tiếp theo kiểm tra xem cột nào có thể khai thác. Gõ lệnh: `1' union select 1,2--`

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

Ta thấy có thể khai thác ở cả hai cột. Tiến hành lấy tên table trong SQLite3 `1' union select 1,sql FROM sqlite_master--` 

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Lấy giá trị từ table users `1' union select username,password FROM users--`. Có được pass admin:


<img src="./img/6.png" alt="normal_acc_TRAbID"/>


Submit thành công 

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** c4K04dtIaJsuWdi
