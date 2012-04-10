// Copyright 2009-2012 Toby Schneider (https://launchpad.net/~tes)
//                     Massachusetts Institute of Technology (2007-)
//                     Woods Hole Oceanographic Institution (2007-)
//                     Goby Developers Team (https://launchpad.net/~goby-dev)
// 
//
// This file is part of the Goby Underwater Autonomy Project Libraries
// ("The Goby Libraries").
//
// The Goby Libraries are free software: you can redistribute them and/or modify
// them under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// The Goby Libraries are distributed in the hope that they will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Goby.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROUTE20120410
#define ROUTE20120410

#include "goby/acomms/protobuf/route.pb.h"
#include "goby/acomms/protobuf/queue.pb.h"
#include "goby/acomms/queue/queue_manager.h"

namespace goby
{
    namespace acomms
    {
        class RouteManager
        {
          public:
            RouteManager();
            ~RouteManager();

            void set_cfg(const protobuf::RouteManagerConfig& cfg);
            void merge_cfg(const protobuf::RouteManagerConfig& cfg);

            void handle_in(const protobuf::QueuedMessageMeta& meta,
                           const google::protobuf::Message& data_msg);
            
            void handle_out(protobuf::QueuedMessageMeta* meta,
                            const google::protobuf::Message& data_msg);

            void add_subnet_queue(uint32 modem_id,
                                  QueueManager* manager);

            bool is_in_route(int modem_id);
            
            
          private:
            RouteManager(const RouteManager&);
            RouteManager& operator= (const RouteManager&);

            void process_cfg();

          private:
            protobuf::RouteManagerConfig cfg_;

            // maps (modem_id & subnet_mask) onto QueueManager
            std::map<uint32, QueueManager*> subnet_map_;
        };
    }
}
















#endif