# Write up challenge SQL injection - Blind

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Server/SQL-injection-blind)<br>
</br>

Truy cập challenge ta thấy bài này là một bài blind sqli. Tên chaallenge cũng như thực hiện các bước kiểm tra đơn giản giản ta cũng đã thấy điều đó 

<img src="./img/2.png" height=350 alt="normal_acc_TRAbID"/> 

<img src="./img/3.png" alt="normal_acc_TRAbID"/>

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

<br>

Bài này sử dụng phương thức POST nên ta sẽ dùng burpsuite

<img src="./img/t.png" alt="normal_acc_TRAbID"/>

Lưu request vào file và kết hợp dùng sqlmap. Khai thác tên bảng `python3 sqlmap/sqlmap.py -r /home/QuynhQuynh/CurrentSemester/NT231/blind.txt --tables  `

<img src="./img/m1.png" alt="normal_acc_TRAbID"/>

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

Kết quả trả về 1 bảng là users. Thực hiện khhai thascduwx liệu bảng `python3 sqlmap/sqlmap.py -r /home/QuynhQuynh/CurrentSemester/NT231/blind.txt -T users --dump`

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

Có được flag. Submit thành công 

<img src="./img/h.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** e2azO93i

