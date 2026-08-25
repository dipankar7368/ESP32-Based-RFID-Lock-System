# 🔐 RFID Based Smart Lock System

# 🔐 RFID Based Smart Lock System

A simple and secure **RFID-based smart door lock system** built using an **ESP32**, **MFRC522 RFID reader**, and **servo motor**.

The system checks the RFID card UID and automatically unlocks the lock when an authorized card is detected. Unauthorized cards are rejected with a buzzer alert.

## 🚀 Features

* 🔑 RFID card authentication
* 🔓 Servo-based door locking mechanism
* 🟢 Green LED for access granted
* 🔴 Red LED for access denied / locked status
* 🔊 Buzzer notification
* ⚡ ESP32-based controller
* ⏱️ Automatic relocking after 3 seconds
* 🖥️ RFID UID displayed in Serial Monitor
* 💻 Easy to customize authorized RFID UID

## 🧰 Components Required

| Component               |    Quantity |
| ----------------------- | ----------: |
| ESP32 Development Board |           1 |
| MFRC522 RFID Reader     |           1 |
| RFID Card/Tag           |          1+ |
| Servo Motor             |           1 |
| Green LED               |           1 |
| Red LED                 |           1 |
| Buzzer                  |           1 |
| Resistors               |           2 |
| Jumper Wires            | As required |
| Breadboard              |           1 |

## 🔌 Pin Configuration

| Component        | ESP32 Pin |
| ---------------- | --------: |
| MFRC522 SDA / SS |    GPIO 5 |
| MFRC522 RST      |   GPIO 22 |
| MFRC522 SCK      |       SPI |
| MFRC522 MOSI     |       SPI |
| MFRC522 MISO     |       SPI |
| Servo Signal     |   GPIO 13 |
| Green LED        |   GPIO 25 |
| Red LED          |   GPIO 26 |
| Buzzer           |   GPIO 27 |

### MFRC522 SPI Connections

| MFRC522  | ESP32   |
| -------- | ------- |
| SDA / SS | GPIO 5  |
| SCK      | GPIO 18 |
| MOSI     | GPIO 23 |
| MISO     | GPIO 19 |
| RST      | GPIO 22 |
| 3.3V     | 3.3V    |
| GND      | GND     |

⚠️ **Important:** The MFRC522 is a **3.3V device**. Do not connect its VCC to 5V.

## 📚 Required Arduino Libraries

Install these libraries through the Arduino IDE Library Manager:

* `MFRC522`
* `ESP32Servo`

The `SPI` library is included with the Arduino framework.

## ⚙️ How It Works

1. ESP32 initializes the RFID reader and servo.
2. The servo starts in the **LOCK** position.
3. The red LED remains ON while the system is locked.
4. Scan an RFID card.
5. ESP32 reads the card's UID.
6. The UID is compared with the authorized UID stored in the program.
7. If the UID matches:

   * 🟢 Green LED turns ON
   * 🔴 Red LED turns OFF
   * 🔓 Servo moves to the OPEN position
   * 🔊 Buzzer gives one beep
8. After 3 seconds, the servo returns to the LOCK position.
9. If the UID does not match:

   * 🔴 Red LED stays ON
   * 🟢 Green LED stays OFF
   * 🔊 Buzzer gives three beeps
   * 🔒 Lock remains closed

## 🪪 Adding Your RFID Card

Upload the program and open the **Serial Monitor** at:

```text
115200 baud
```

Scan your RFID card.

The Serial Monitor will show something like:

```text
UID: A1 67 46 54
```

Copy your UID and replace:

```cpp
String authorizedUID = "A1 67 46 54";
```

with your card's UID.

Example:

```cpp
String authorizedUID = "12 AB 34 CD";
```

## 📁 Project Structure

```text
RFID-Smart-Lock/
│
├── RFID-Smart-Lock.ino
├── README.md
└── LICENSE
```

## 🧠 Main Technologies

* **ESP32**
* **Arduino IDE**
* **RFID / NFC**
* **MFRC522**
* **SPI Communication**
* **Servo Motor**
* **Embedded C/C++**

## 🔒 Security Note

This project is designed as an **educational DIY smart-lock project**. UID-based RFID authentication alone should not be considered high-security access control because RFID card UIDs can potentially be copied or spoofed.

For a real security system, consider adding additional authentication such as a PIN, encrypted authentication, or another secure access method.

## 📺 YouTube Demo

🎥 Watch the complete project demonstration:

**[▶️ Watch the Project on YouTube](https://youtube.com/shorts/H5joutr80_g?si=rS4H7rnjZD4t9ponUG)**


More IoT, robotics, embedded systems, Arduino, ESP32 and DIY electronics projects are available on the channel.

## 👨‍💻 Author

**Dipankar Bhunia**

🔧 IoT • Embedded Systems • Robotics • Arduino • ESP32 • DIY Electronics

## ⭐ Support

If you found this project useful:

⭐ Star this repository
🍴 Fork the project
🐛 Report issues
💡 Share your improvements

---

### 📜 License

This project is open-source and intended for educational and personal DIY use.
