# 🌐 Wireless Network Analyzer/ Network Packet Sniffer

A C++ program that captures and analyzes network packets using the libpcap library. This tool displays packet information including timestamps, packet length, and MAC addresses.

## ✨ Features

- 📡 Real-time packet capture
- 🔍 MAC address extraction and formatting
- ⏱️ Packet timestamp logging
- 📊 Packet size analysis
- 🔄 Continuous packet monitoring

## 📋 Prerequisites

- 🖥️ Linux/Unix Operating System
- ⚡ GCC/G++ Compiler
- 📦 libpcap-dev package
- 👑 Root/Administrative privileges

## 🚀 Installation

1. Install libpcap development package:
```bash
sudo apt-get install libpcap-dev
```

2. Clone this repository:
```bash
git clone https://github.com/ybigsur5/packet-sniffer.git
```

3. Compile the program:
```bash
g++ packet_sniffer.cpp -o packet_sniffer -lpcap
```

## 💻 Usage

1. Run the program with root privileges:
```bash
sudo ./packet_sniffer
```

The program will:
- 🔍 Automatically detect network interface
- 📡 Start capturing packets
- 📊 Display packet information in real-time
- 🔄 Continue until manually stopped (Ctrl+C)

## 📝 Output Format

For each captured packet, the program displays:
```
Packet captured!
Timestamp: [seconds].[microseconds]
Packet length: [length] bytes
Source MAC: xx:xx:xx:xx:xx:xx
Dest MAC: xx:xx:xx:xx:xx:xx
```

## ⚠️ Limitations

- 👑 Requires root privileges
- 🐧 Linux/Unix systems only
- 🔌 Depends on libpcap library

## 🔒 Security Considerations

- ⚠️ Only run on networks you have permission to monitor
- 🛡️ Be aware of privacy and legal implications
- 🔐 Handle captured data responsibly

## 🚀 Future Enhancements

1. Add protocol analysis (TCP/IP, UDP)
2. Implement packet filtering
3. Add packet payload inspection
4. Create packet statistics
5. Add GUI interface

## 👨‍💻 Author

**Vira**
- 🌐 GitHub: [@ybigsur5](https://github.com/ybigsur5)
- 📧 Email: vira.cehoscp@gmail.com

## 🙏 Acknowledgments

- 📚 libpcap documentation
- 🛡️ Network Security Community
- 👥 Open Source Contributors

## ⚠️ Disclaimer

This tool is for educational purposes only. Ensure you have proper authorization before capturing network traffic. Use responsibly and ethically.
