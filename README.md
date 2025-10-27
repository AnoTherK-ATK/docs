# AnoTherK's docs

Một nơi tôi viết những thứ mà tôi đã học theo cách tôi hiểu. Đơn giản hoá quá mức cần thiết.
Định hướng ban đầu của nó sẽ là về lập trình cơ bản (Nhập môn Lập trình và DSA).
Trang này ban đầu là thuần tiếng Việt nhưng ai biết được tương lai nó sẽ như thế nào.

## Bạn muốn đóng góp cho trang?

Thật luôn, bạn muốn viết thêm vào đây à. Chỉ cần clone về:

```sh
git clone https://github.com/AnoTherK-ATK/docs.git
```

Dùng `pnpm` để tải module:

```sh
pnpm install
```

Chạy bằng `pnpm` luôn:

```sh
pnpm run dev
```

Những gì bạn cần chỉnh là ở trong thư mục [`src/content/docs`](https://github.com/AnoTherK-ATK/docs/tree/main/src/content/docs). Hãy mở một thư mục với topic bạn muốn viết hoặc tự tạo một thư mục về topic mới.

Bạn sẽ muốn đọc qua cú pháp của [markdown](https://www.markdownguide.org/), [starlight](https://starlight.astro.build/) ~~đẹp vl~~ và [mermaid](https://mermaid.js.org/) để có được trải nghiệm viết tốt nhất.

### Components có sẵn

- **Quiz Component**: Component quiz hỗ trợ multiple choice và multiple answer với tính điểm tự động. Xem [`src/components/README-quiz.md`](src/components/README-quiz.md) để biết cách sử dụng.
- **VideoPlayer Component**: Component video player sử dụng Plyr

Sau đó gửi pull request lên đây, tôi sẽ xem và duyệt.

Have fun.