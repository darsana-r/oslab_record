import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;


public class udp_echo_client{
	public static void main(String[] args)throws IOException{
		try{

			DatagramSocket datagramSocket=new DatagramSocket(5000);
			byte buffer[]=new byte[256];

			System.out.print("Enter msg to server: ");
			Scanner from_client=new Scanner(System.in);
			String op=from_client.nextLine();
			
			DatagramPacket outpacket=new DatagramPacket(op.getBytes(),op.length(),InetAddress.getLocalHost(),4000);
			datagramSocket.send(outpacket);

			DatagramPacket inpacket=new DatagramPacket(buffer,buffer.length);
			datagramSocket.receive(inpacket);

			String msg= new String(inpacket.getData(),0,inpacket.getLength());

			System.out.println("return message from server: "+msg);

			datagramSocket.close();

			
		}catch(Exception e){
			System.out.println(e);
		}
		
		
	}
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b/echo$ javac udp_echo_server.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b/echo$ java udp_echo_server
Message from client: hai


pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b/echo$ javac udp_echo_client.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b/echo$ java udp_echo_client
Enter msg to server: hai
return message from server: hai
*/


