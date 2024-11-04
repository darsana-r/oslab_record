import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;


public class udp_chat_client{
	public static void main(String[] args)throws IOException{
		try{

			DatagramSocket datagramSocket=new DatagramSocket(5000);
			while(true){
				byte buffer[]=new byte[256];

				System.out.print("Enter msg to server: ");
				Scanner from_client=new Scanner(System.in);
				String op=from_client.nextLine();
			
				DatagramPacket outpacket=new DatagramPacket(op.getBytes(),op.length(),InetAddress.getLocalHost(),4000);
				datagramSocket.send(outpacket);
				
				if(op.equals("stop")){
					break;
				}

				DatagramPacket inpacket=new DatagramPacket(buffer,buffer.length);
				datagramSocket.receive(inpacket);

				String msg= new String(inpacket.getData(),0,inpacket.getLength());

				System.out.println("Message from server: "+msg);
				if(msg.equals("stop")){
					break;
				}
			}
			
			datagramSocket.close();

			
		}catch(Exception e){
			System.out.println(e);
		}
		
		
	}
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ javac udp_chat_server.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ java udp_chat_serverMessage from client: stop

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ javac udp_chat_client.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ java udp_chat_client
Enter msg to server: hai
Message from server: hai
Enter msg to server: stop

*/
