#ifndef GT_NET_SELECT_WRAPPER_
#define GT_NET_SELECT_WRAPPER_

#include <string>

#include "GT_Select_Core.h"
#include "GT_Definition.h"
#include "GTUtlity/GT_Util_CfgHelper.h"
#include "GTUtlity/GT_Util_GlogWrapper.h"

namespace GT {
    namespace NET {

        class GT_Select_Wrapper
        {
        public:
            GT_Select_Wrapper();
            ~GT_Select_Wrapper();

		public:
			bool	Initialize(std::string cfg_path);
			bool	Finalize();

			void	RegisterSelectCallBack();
			void	RegisterCallBack(gt_event_callback cb, EVENT_TYPE type);
			void	StartService();
			static  void	DispatchEvent(EVENT_TYPE type, intptr_t, char*, int);
		private:
			static gt_event_callback read_cb;
			static gt_event_callback write_cb;
			GT_LOG_LEVEL LoglevelConvert(std::string loglevel);
		private:
			GT_Select_Core	select_core_;
			bool	service_started_;
			bool	service_inited_;
        };
    }
}

#endif
