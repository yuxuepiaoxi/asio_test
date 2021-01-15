//
// main.cpp
// ~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

/*
boost asio����http���÷����£�
1 ��main�����е���server��Ĺ��캯�� ��������
2 ��server���е�����connection_manager��
3 ��connection_manager���е�����connection ��������ص�Ҫ��ע��һ���� ������
  ���ݵĶ�ȡdo_read()�����Լ����ݵ�д��do_write()����
  �����ݵĶ�ȡ���ڲ�����������request_parser���ڽ������������
  ��������󣬵���request_handler�н��н������ݵķ�������������reply�������Ӧ���ݵķ���
*/

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "server.hpp"

int main(int argc, char* argv[])
{
  try
  {
    // Check command line arguments.
    //if (argc != 4)
    //{
    //  std::cerr << "Usage: http_server <address> <port> <doc_root>\n";
    //  std::cerr << "  For IPv4, try:\n";
    //  std::cerr << "    receiver 0.0.0.0 80 .\n";
    //  std::cerr << "  For IPv6, try:\n";
    //  std::cerr << "    receiver 0::0 80 .\n";
    //  return 1;
    //}

    //// Initialise the server.
    //http::server::server s(argv[1], argv[2], argv[3]);

	const std::string ip = "127.0.0.1";
	const std::string port = "8090";
	const std::string docroot = "./docs";
	// 1 ��һ����main��������server�� �������������ǳ�ʼ��server�еĹ��캯�� ��һ����server.cpp��
	http::server::server s(ip, port, docroot);
    // Run the server until stopped.
    s.run();
  }
  catch (std::exception& e)
  {
    std::cerr << "exception: " << e.what() << "\n";
  }

  return 0;
}
