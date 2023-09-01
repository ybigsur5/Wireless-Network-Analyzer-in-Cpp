#include <iostream>
#include <pcap.h>
#include <netinet/in.h>

void
packetHandler (unsigned char *userData, const struct pcap_pkthdr *pkthdr,
	       const unsigned char *packetData)
{
  std::cout << "Packet captured!" << std::endl;
  std::cout << "Timestamp: " << pkthdr->ts.tv_sec << "." << pkthdr->ts.
    tv_usec << std::endl;
  std::cout << "Packet length: " << pkthdr->len << " bytes" << std::endl;

  const struct ether_header *ethHeader =
    reinterpret_cast < const struct ether_header *>(packetData);

  char srcMac[18];
  char destMac[18];
  sprintf (srcMac, "%02x:%02x:%02x:%02x:%02x:%02x",
	   ethHeader->ether_shost[0], ethHeader->ether_shost[1],
	   ethHeader->ether_shost[2], ethHeader->ether_shost[3],
	   ethHeader->ether_shost[4], ethHeader->ether_shost[5]);
  sprintf (destMac, "%02x:%02x:%02x:%02x:%02x:%02x",
	   ethHeader->ether_dhost[0], ethHeader->ether_dhost[1],
	   ethHeader->ether_dhost[2], ethHeader->ether_dhost[3],
	   ethHeader->ether_dhost[4], ethHeader->ether_dhost[5]);

  std::cout << "Source MAC: " << srcMac << std::endl;
  std::cout << "Dest MAC: " << destMac << std::endl;

}

int
main ()
{
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];

  device = pcap_lookupdev (errbuf);
  if (device == nullptr)
    {
      std::cerr << "Error finding a network device: " << errbuf << std::endl;
      return 1;
    }

  pcap_t *handle;
  handle = pcap_open_live (device, BUFSIZ, 1, 1000, errbuf);
  if (handle == nullptr)
    {
      std::
	cerr << "Error opening device " << device << ": " << errbuf << std::
	endl;
      return 1;
    }

  pcap_loop (handle, 0, packetHandler, nullptr);

  pcap_close (handle);

  return 0;
}
