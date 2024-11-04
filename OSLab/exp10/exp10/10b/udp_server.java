import java.io.*;
import java.util.*;
import java.net.*;
import java.lang.*;

public class udp_server{
	public static void main(String[] args)throws IOException{
		try{
			DatagramSocket datagramsocket=new DatagramSocket(4000);
			byte buffer[]=new byte[256];
			
			System.out.println("Waiting for connection...");
			DatagramPacket inpacket=new DatagramPacket(buffer,buffer.length);
			datagramsocket.receive(inpacket);
			

			String msg= new String(inpacket.getData(),0,inpacket.getLength());
			System.out.println("Message from client: "+msg);

			InetAddress client_addr=inpacket.getAddress();
			int client_port=inpacket.getPort();
		
			System.out.print("Enter msg to client: ");
			Scanner reply=new Scanner(System.in);
			String response=reply.nextLine();
		
			DatagramPacket outpacket=new DatagramPacket(response.getBytes(),response.length(),client_addr,client_port);
			datagramsocket.send(outpacket);
			datagramsocket.close();

		}catch(Exception e){
			System.out.println(e);
		}
			
	}
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10a$ javac udp_server.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ java udp_serverWaiting for connection...
Message from client: hi,i am client
Enter msg to client: hello,i am server


pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ javac udp_client.java
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp10/10b$ java udp_client
Enter msg to server: hi,i am client
Message from server: hello,i am server
*/
