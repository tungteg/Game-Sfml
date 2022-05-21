I, **Hướng dẫn cài đặt thư viện SFML TRÊN DEV C++**
 1. Mở dev c++, trên thanh công cụ chọn Project -> chọn Project Options
 2. Chọn Parameters, trong Linker chúng ta dán 4 dòng sau vào:
   *-lsfml-audio
   *-lsfml-graphics
   *-lsfml-window
   *-lsfml-system 
 3. Chọn Directories, *trong Libary Directories chúng ta add đường dẫn: SFML-2.4.2\lib
                       *trong Include Directories ta add đường dẫn: SFML-2.4.2\include
 4. chọn OK, thế là xong các bước cài đặt thư viện sfml vào dev c++. Video hướng dẫn chi tiết (https://www.youtube.com/watch?v=uAd2jINKCxc).
 
II, **Mô tả chung về trò chơi, các ý tưởng chính**
* Snake Game: được xây dựng lại dựa trên game rắn săn mồi trong điện thoại nokia 1280, game dược bằng cách điều khiển chú rắn đi ăn mồi xung quannh một map, mỗi lần ăn một quả cherry rắn được dài thêm một đốt, nếu rắn cắn vào thân hoặc lao vào tường thì rắn sẽ bị chết và phải chơi lại từ đầu.
* các ý tưởng: các chế độ chơi khác nhau, các skin rắn khác nhau.

III, **Mô tả các chức năng đã cài đặt**
 1. gồm 2 chế độ chơi: classic và modern 
  1.1 classic: là chế độ rắn không có tường và chui lại từ tưởng đối diện.
  1.2 modern:  là chế có tường và khi rắn lao vào tưởng thì sẽ bị chết.
 2. có 5 chế độ tốc độ khác nhau
