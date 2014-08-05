// Copyright (c) 2014, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#include "include_base_utils.h"
#include "net/http_client.h"
#include "wallet/wallet_rpc_server.h"

int main(int argc, char** argv)
{
  epee::net_utils::http::http_simple_client http_client;
  bool r = http_client.connect("localhost", "1337", 200000);
  std::cout << r;
  epee::json_rpc::request<tools::wallet_rpc::COMMAND_RPC_QUERY_KEY::request> req_t = AUTO_VAL_INIT(req_t);
  epee::json_rpc::response<tools::wallet_rpc::COMMAND_RPC_QUERY_KEY::response, epee::json_rpc::error> resp_t = AUTO_VAL_INIT(resp_t);
  tools::wallet_rpc::COMMAND_RPC_QUERY_KEY::request req = AUTO_VAL_INIT(req);

  req_t.jsonrpc = "2.0";
  req_t.id = "10";
  req_t.method = "query_key";
  req.key_type ="view_key";
  req_t.params = req; 
 
 
 //bool r2 = epee::net_utils::invoke_http_json_remote_command2("/rpc/v2/query_key", req, res, http_client, 2000);
 bool r2 = epee::net_utils::invoke_http_json_remote_command2("http://localhost:1337/json_rpc", req_t, resp_t, http_client, 200000);
 
 std::cout << "result code " << resp_t.error.message;
 std::cout << "result is " << resp_t.result.key;
 //std::cout << "result is " << res.address;


}
