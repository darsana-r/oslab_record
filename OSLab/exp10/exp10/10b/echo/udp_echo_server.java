import java.util.*;
import java.io.*;
import java.net.*;
import java.lang.*;

public class udp_echo_server{
	public static void main(String[] args)throws IOException{
		try{
			DatagramSocket datagramsocket=new DatagramSocket(4000);
			
			byte buffer[]=new byte[256];
				
			DatagramPacket inpacket=new DatagramPacket(buffer,buffer.length);
			datagramsocket.receive(inpacket);
		
			String msg= new String(inpacket.getData(),0,inpacket.getLength());
			System.out.println("Message from client: "+msg);
				
			InetAddress client_addr=inpacket.getAddress();
			int client_port=inpacket.getPort();
		
			DatagramPacket outpacket=new DatagramPacket(msg.getBytes(),msg.length(),client_addr,client_port);
			datagramsocket.send(outpacket);
				
			datagramsocket.close();

		}catch(Exception e){
			System.out.println(e);
		}
			
	}
}                                               
