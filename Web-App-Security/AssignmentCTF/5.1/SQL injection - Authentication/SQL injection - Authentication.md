# Write up challenge SQL injection - Authentication

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/SQL-injection-authentication)<br>
</br>

Truy cập challenge ta thấy có một form login.
Thử tiến hành một sqli basic attack

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

Thành công đăng nhập dưới quyền admin

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

Tat thấy có một form information chứa password bị hide, tiến hành inspect xem thử ta có được flag:

<img src="./img/3.png" alt="normal_acc_TRAbID"/>


Submit thành công 

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** t0_W34k!$
