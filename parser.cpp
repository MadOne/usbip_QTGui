#include <QStringList>

/*
 - busid 2-3 (1058:25a3)
   Western Digital Technologies, Inc. : unknown product (1058:25a3)

 - busid 3-3.2 (046d:c52b)
   Logitech, Inc. : Unifying Receiver (046d:c52b)

 - busid 3-3.3 (046d:c52b)
   Logitech, Inc. : Unifying Receiver (046d:c52b)

 - busid 3-3.4 (058f:6366)
   Alcor Micro Corp. : Multi Flash Reader (058f:6366)

 - busid 4-1 (174c:55aa)
   ASMedia Technology Inc. : ASM1051E SATA 6Gb/s bridge, ASM1053E SATA 6Gb/s bridge, ASM1153 SATA 3Gb/s bridge (174c:55aa)

 - busid 5-1 (054c:0268)
   Sony Corp. : Batoh Device / PlayStation 3 Controller (054c:0268)

*/

QStringList parse_local(QString text)
{
  QStringList devices = text.split("\n\n");
  QStringList deviceReturn;
  for (const auto &item : devices)
  {
    QStringList lines = item.split("\n");
    if (lines.length() > 1)
    {
      QString busid = lines[0].split(" ")[3];
      QString manufacturer = lines[1].split(":")[0];
      QString description = lines[1].split(":")[1] + ":" + lines[1].split(":")[2];
      deviceReturn.append(busid);
      deviceReturn.append(manufacturer);
      deviceReturn.append(description);
    }
  }
  return deviceReturn;
}

/*
Exportable USB devices
======================
 - 192.168.1.103
      1-1.3: SanDisk Corp. : Cruzer (0781:5530)
           : /sys/devices/platform/soc/20980000.usb/usb1/1-1/1-1.3
           : (Defined at Interface level) (00/00/00)
           :  0 - Mass Storage / SCSI / Bulk-Only (08/06/50)


*/

QStringList parseRemote(QString text)
{
  QStringList returnVal = {};
  QStringList lines = text.split("\n");
  if (lines.length() < 7)
  {
    return returnVal;
  }
  int deviceCount = (lines.length() - 3) / 4;
  QString ip = lines[2].split(" - ")[1];

  for (int i = 0; i < deviceCount; i++)
  {
    QString lineBusid = lines[i * 4 + 3];
    QString busid = lineBusid.split(":")[0];
    QString manufacturer = lineBusid.split(":")[1];
    QString description = lineBusid.split(":")[2] + ":" + lineBusid.split(":")[3];

    returnVal.append(busid);
    returnVal.append(manufacturer);
    returnVal.append(description);
  }
  return returnVal;
}

/*sample output to parse for parse_attached_list(text)

Imported USB devices
====================
Port 00: <Port in Use> at Full Speed(12Mbps)
       Sony Corp. : Batoh Device / PlayStation 3 Controller (054c:0268)
       5-1 -> usbip://192.168.1.103:3240/1-1.4
           -> remote bus/dev 001/005
*/

QStringList parseAttached(QString text)
{

  QStringList returnVal = {};
  QStringList lines = text.split("\n");
  int devices = (lines.length() - 2) / 4;
  for (int i = 0; i < devices; i++)
  {
    int startline = 2 + i * 4;
    QString port = lines[startline].split(" ")[1];
    port.chop(1);
    QStringList line2 = lines[startline + 1].split(":");
    QString manufacturer = line2[0];
    QString description = line2[1] + ":" + line2[2];
    QStringList line3 = lines[startline + 2].split("/");
    QString busID = line3[line3.length() - 1];
    QString ip = line3[line3.length() - 2];
    returnVal.append(ip);
    returnVal.append(port);
    returnVal.append(busID);
    returnVal.append(manufacturer);
    returnVal.append(description);
  }

  return returnVal;
}

QStringList parseModules(QString lsmod)
{
  QStringList lines = lsmod.split("\n");
  QStringList missingModules = {"usbip_host", "usbip_core", "vhci_hcd"};
  for (const auto &line : lines)
  {
    QStringList items = line.split(" ");
    if (items[0] == "usbip_host" || items[0] == "usbip_core" || items[0] == "vhci_hcd")
    {
      missingModules.removeAll(items[0]);
    }
  }
  return missingModules;
}