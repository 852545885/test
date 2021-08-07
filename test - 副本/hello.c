while (1)
	{
        len = UART_Recv(fdSerial, rcv_buf, 1024, 10000);
        if (len > 0)
        {
            if (-1 == send(Client_Socket, rcv_buf, strlen(rcv_buf) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
            rcv_buf[len] = '\0';
			for(i=0;i<16;i++)
			{
				time[i]=rcv_buf[i+12];
			}
			Winddir[0]=rcv_buf[105];
			Winddir[1]=rcv_buf[106];
			if (-1 == send(Client_Socket, Winddir, strlen(Winddir) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
			Windsp[0]=rcv_buf[108];
			Windsp[1]=rcv_buf[109];
			if (-1 == send(Client_Socket, Windsp, strlen(Windsp) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
			Rain[0]=rcv_buf[131];
				if (-1 == send(Client_Socket, Rain, strlen(Rain) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
			Tem[0]=rcv_buf[135];
			Tem[1]=rcv_buf[136];
				if (-1 == send(Client_Socket, Tem, strlen(Tem) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
			Hum[0]=rcv_buf[143];
			Hum[1]=rcv_buf[144];
				if (-1 == send(Client_Socket, Hum, strlen(Hum) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
			Press[0]=rcv_buf[150];
			Press[1]=rcv_buf[151];
            Press[2]=rcv_buf[152];
			Press[3]=rcv_buf[153];
			Press[4]='.';
			Press[5]=rcv_buf[154];
				if (-1 == send(Client_Socket, Press, strlen(Press) + 1, 0))
            {
                perror("Sending failure!");
                break;
            }
			//Windsp=(rcv_buf[108]-'0') * 10 + (rcv_buf[109] - '0');
			//Rain=(rcv_buf[131]-'0');
			//Tem=(rcv_buf[135]-'0') * 10 + (rcv_buf[136] - '0');
			//Hum=(rcv_buf[143]-'0') * 10 + (rcv_buf[144] - '0');
			//Press=(rcv_buf[150]-'0') * 1000 + (rcv_buf[151] - '0')* 100+(rcv_buf[152] - '0')* 10+(rcv_buf[153] - '0')* 1+(rcv_buf[154] - '0')* 0.1;
			
            printf("uart receive data is %s\n", rcv_buf);
			//printf("receive time is %s\n", time);
			//printf("receive Winddir is %d\n", Winddir);
			//printf("receive Windsp is %d\n", Windsp);
			//printf("receive Rain is %d\n", Rain);
			//printf("receive Tem is %d\n", Tem);
			//printf("receive Hum is %d\n", Hum);
			//printf("receive Press is %d\n", Press);
            printf("len = %d\n", len);
            bzero(rcv_buf, BUF_SIZE);//清零字符串
        }
	}

	close(Client_Socket);

	return 0;
}