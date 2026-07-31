#include "common/macros.h"
#include "common/nndef.h"
#include "gameroot.h"
#include "logic/timeoutlogic/core/actiontimeout.h"
#include "logic/clientlogic/core/decision.h"
#include "utils/tarslog.h"
#include "context/context.h"
#include "process/process.h"
#include "message/sendclientmessage.h"
#include "logic/gamelogic/core/begintimer.h"
#include "logic/gamelogic/core/endtimer.h"
#include "config/gameconfig.h"
#include "common/nndef.h"
#include "common/nnlogic.h"
#include "ddz.pb.h"

using namespace nndef;

namespace game
{
    namespace logic
    {
        namespace timeoutlogic
        {
            using namespace context;
            using namespace process;
            using namespace message;
            using namespace gamelogic;
            using namespace config;
            using namespace clientlogic;

            void ActionTimeOut(GameRoot *root)
            {
                PERFSTATS_ENTRY();
                __TRY__

                DLOG_TRACE("roomid:" << root->roomid() << ", " << "ActionTimeOut roomid:" << root->roomid());

                cid_t tokencid = root->con->getTokenCid();
                User *user = root->con->getUserByCid(tokencid);
                if(!user)
                {
                    DLOG_TRACE("roomid:" << root->roomid() <<"ActionTimeOut err process: "<< root->pro->getProcess() <<" , tokencid: "<< tokencid ); 
                    return;
                }
                
                if(root->pro->getProcess() == NN_STATE_JIABEI)//加倍
                {
                    std::map<cid_t, User> &usermap = root->con->refUserMap();
                    for (auto it = usermap.begin(); it != usermap.end(); it++)
                    {
                        XGameDDZProto::DDZ_msg2csDecision shcm;
                        if(!it->second.isReady() || user->getMultiple() > 0)
                        {
                            DLOG_TRACE("roomid:" << root->roomid() <<", cid: "<< it->first <<" ,uid: "<< it->second.getUid() <<", isReady: "<<it->second.isReady()<<", mulit: "<< user->getMultiple() );
                            continue;
                        }
                        shcm.set_icid(it->first);
                        shcm.set_iacttype(root->pro->getProcess() -1);
                        vector<char> vecOutBuffer;
                        pbTobuffer(shcm, vecOutBuffer);
                        clientlogic::Decision(it->second.getUid(), vecOutBuffer, root);
                    }
                }
                else
                {
                    XGameDDZProto::DDZ_msg2csDecision shcm;
                    shcm.set_icid(root->con->getTokenCid());
                    shcm.set_iacttype(root->pro->getProcess() -1);
                    //shcm.set_iparam(root->pro->getProcess() == NN_STATE_JIAODIZHU ? 3 : 0);
                    
                    //有牌权时， 出一张最小牌
                    if(root->pro->getProcess() == NN_STATE_DAPAI)
                    {
                        auto last_decision = root->con->getLastDecision();
                        if((last_decision.size() == 0 || (last_decision.size() > 0 &&  root->con->getLastDecision().begin()->first == user->getCid())) && user->getVecCards().size() > 0)
                        {
                            //排序
                            vecc_t &vecCards = user->refVecCards();
                            std::sort(vecCards.begin(), vecCards.end(), [](card_t l, card_t r)->bool{
                                if(nncard::getNNType(l) == E_NN_CARD::NN_CARD_KING || nncard::getNNType(r) == E_NN_CARD::NN_CARD_KING)
                                {
                                    return nncard::getNNType(r) == E_NN_CARD::NN_CARD_KING;
                                }
                                return nncard::getNNNum(l) < nncard::getNNNum(r);            
                            });
                            shcm.add_scards(*vecCards.begin());
                        }
                        user->setTimeOut(user->getTimeOut() + 1);
                    }
                   
                    vector<char> vecOutBuffer;
                    pbTobuffer(shcm, vecOutBuffer);
                    clientlogic::Decision(user->getUid(), vecOutBuffer, root, true);
                }
                __CATCH__
                PERFSTATS_EXIT();
            }
        }
    }
}
