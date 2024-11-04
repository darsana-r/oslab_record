import java.util.*;
import java.io.*;
import java.net.*;
import java.lang.*;

public class udp_chat_server{
	public static void main(String[] args)throws IOException{
		try{
			DatagramSocket datagramsocket=new DatagramSocket(4000);
			
			while(true){
				
				byte buffer[]=new byte[256];
			
				
				DatagramPacket inpacket=new DatagramPacket(buffer,buffer.length);
				datagramsocket.receive(inpacket);
			

				String msg= new String(inpacket.getData(),0,inpacket.getLength());
				System.out.println("Message from client: "+msg);
				
				if(msg.equals("stop")){
					break;
				}

				InetAddress client_addr=inpacket.getAddress();
				int client_port=inpacket.getPort();
		
				System.out.print("Enter msg to client: ");
				Scanner reply=new Scanner(System.in);
				String response=reply.nextLine();
		
				DatagramPacket outpacket=new DatagramPacket(response.getBytes(),response.length(),client_addr,client_port);
				datagramsocket.send(outpacket);
				
				if(response.equals("stop")){
					break;
				}

				
			}
			
			datagramsocket.close();

		}catch(Exception e){
			System.out.println(e);
		}
			
	}
}
