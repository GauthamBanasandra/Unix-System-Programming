!function(){function e(e,t){return"function"==typeof __an_obj_extend_thunk?__an_obj_extend_thunk(e,t):e}function t(e,t){"function"==typeof __an_err_thunk&&__an_err_thunk(e,t)}function n(e){"function"==typeof __an_redirect_thunk?__an_redirect_thunk(e):document.write('<script language="javascript" src="'+e+'"></scr'+'ipt>')};var r=function(e){this.rdParams=e};r.prototype={constructor:r,walkAncestors:function(e){try{if(!window.location.ancestorOrigins)return;for(var t=0,n=window.location.ancestorOrigins.length;n>t;t++)e.call(null,window.location.ancestorOrigins[t],t)}catch(r){"undefined"!=typeof console}return[]},walkUpWindows:function(e){var t,n=[];do try{t=t?t.parent:window,e.call(null,t,n)}catch(r){return"undefined"!=typeof console,n.push({referrer:null,location:null,isTop:!1}),n}while(t!==window.top);return n},getPubUrlStack:function(e){var n,r=[],o=null,i=null,c=null,d=null,a=null,s=null,u=null;for(n=e.length-1;n>=0;n--){try{c=e[n].location}catch(l){"undefined"!=typeof console,t(l,"AnRDModule::getPubUrlStack:: location")}if(c)i=encodeURIComponent(c),r.push(i),u||(u=i);else if(0!==n){d=e[n-1];try{a=d.referrer,s=d.ancestor}catch(l){"undefined"!=typeof console,t(l,"AnRDModule::getPubUrlStack:: prevFrame")}a?(i=encodeURIComponent(a),r.push(i),u||(u=i)):s?(i=encodeURIComponent(s),r.push(i),u||(u=i)):r.push(o)}else r.push(o)}return{stack:r,detectUrl:u}},getLevels:function(){var e=this.walkUpWindows(function(e,n){try{n.push({referrer:e.document.referrer||null,location:e.location.href||null,isTop:e===window.top})}catch(r){n.push({referrer:null,location:null,isTop:e===window.top}),"undefined"!=typeof console,t(r,"AnRDModule::getLevels")}});return this.walkAncestors(function(t,n){e[n].ancestor=t}),e},getRefererInfo:function(){var e="";try{var n=this.getLevels(),r=n.length-1,o=null!==n[r].location||r>0&&null!==n[r-1].referrer,i=this.getPubUrlStack(n);e=this.rdParams.rdRef+"="+i.detectUrl+"&"+this.rdParams.rdTop+"="+o+"&"+this.rdParams.rdIfs+"="+r+"&"+this.rdParams.rdStk+"="+i.stack+"&"+this.rdParams.rdQs}catch(c){e="","undefined"!=typeof console,t(c,"AnRDModule::getRefererInfo")}return e}};var o=function(n){var o="";try{n=e(n,0);var i=e(new r(n),1);return i.getRefererInfo()}catch(c){o="","undefined"!=typeof console,t(c,"AnRDModule::executeRD")}return o};;var i=function(e){this.viewParams=e};i.prototype={constructor:i,getAbsolutePositionIE:function(e,t){var n=e.document.documentElement.clientLeft||e.document.body.clientLeft,r=e.document.documentElement.clientTop||e.document.body.clientTop,o=e.document.documentElement.scrollLeft||e.document.body.scrollLeft,i=e.document.documentElement.scrollTop||e.document.body.scrollTop,c=t.getBoundingClientRect().left+o-n,d=t.getBoundingClientRect().top+i-r;return{x:c,y:d}},getAbsolutePositionFireFox:function(e,t){var n=e.document.documentElement,r=e.getComputedStyle(n,""),o=0,i=0;if(r){var c=t.getBoundingClientRect();o=c.left+parseInt(r.borderLeftWidth,10)+n.scrollLeft,i=c.top+parseInt(r.borderTopWidth,10)+n.scrollTop}return{x:o,y:i}},getAbsolutePositionChrome:function(e,t){if(null===t.offsetLeft)return 0;var n=0,r=t.parentNode;if(r)for(;r.offsetParent;)n-=r.scrollLeft,r=r.parentNode;for(var o,i=t;i&&(n+=i.offsetLeft,o=i.offsetParent,!o||"BODY"!==o.tagName||"absolute"!==i.style.position);)i=o;var c=e.getComputedStyle(e.document.documentElement,""),d=t.getBoundingClientRect().top+parseInt(c.borderTopWidth,10)+e.scrollY;return{x:n,y:d}},injectVirtualElement:function(){document.write('<img id="_anxfe" width="0" height="0" style="display: block; margin: 0px; padding: 0px; width: 0px;">');var e=document.getElementById("_anxfe");return e.removeAttribute("id"),e},isInView:function(e,t,n){var r=e.x,o=e.y;return t>r&&r>=0&&n>o&&o>=0},getAbsolutePosition:function(e,t){var n,r=navigator.userAgent.toLowerCase();return n=-1!==r.indexOf("webkit")?this.getAbsolutePositionChrome(e,t):-1!==r.indexOf("msie")?this.getAbsolutePositionIE(e,t):this.getAbsolutePositionFireFox(e,t)},isFriendlyFrame:function(){try{return!!top.location.href}catch(e){return!1}},getViewabilityData:function(e){var t,n,r,o=0,i=this.isFriendlyFrame();if(!i&&void 0===e.mozInnerScreenY)return{s:1};if(i){var c=this.injectVirtualElement();t=this.getAbsolutePosition(e,c);for(var d,a,s=e;s!=e.top;){try{a=s.frameElement}catch(u){return{s:4}}if(null===a)return{s:5};s=s.parent,d=this.getAbsolutePosition(s.parent,a),t={x:t.x+d.x,y:t.y+d.y}}var l=s.innerWidth||s.document.documentElement.clientWidth||s.document.body.clientWidth,f=s.innerHeight||s.document.documentElement.clientHeight||s.document.body.clientHeight;r={x:l,y:f},n=this.isInView(t,l,f)}else void 0!==e.mozInnerScreenY&&(t={x:e.mozInnerScreenX-e.screenX-4,y:e.mozInnerScreenY-e.screenY-40},r={x:screen.width-8,y:screen.height-119},n=this.isInView(t,r.x,r.y));return(void 0!==n&&void 0!==document.hidden&&document.hidden||i&&!e.top.document.hasFocus())&&(n=!1,o=3),{p:t,w:r,v:n,s:o}}};var c=function(n){var r,o="";try{n=e(n,0);var c=e(new i(n),1),d=c.getViewabilityData(window);void 0!==d.v&&(o+="&"+n.iv+"="+(d.v?1:0)),void 0!==d.p&&(o+="&"+n.pos+"="+Math.round(d.p.x)+","+Math.round(d.p.y)),void 0!==d.w&&(o+="&"+n.ws+"="+Math.round(d.w.x)+","+Math.round(d.w.y)),window.v=d}catch(a){"undefined"!=typeof console,r=2,t(a,"AnViewModule::executeViewability")}return void 0!==r&&(o+="&"+n.vs+"="+r),"undefined"!=typeof console,o};;var d=function(e){e=e?e:{};var t={};t.idsStaleMs="idsStaleSec"in e?1e3*e.idsStaleSec:0,t.criBidderId="criBidderId"in e?e.criBidderId:"0",t.criId="criId"in e?e.criId:"0",t.ids=e.ids,t.criteoFun=e.criteoFun,this.params=t,"undefined"!=typeof console};d.prototype={constructor:d,Util:{Base64:{keyStr:"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=",encode:function(e){var t,n,r,o,i,c,d,a="",s=0;for(e=this.utf8Encode(e);s<e.length;)t=e.charCodeAt(s++),n=e.charCodeAt(s++),r=e.charCodeAt(s++),o=t>>2,i=(3&t)<<4|n>>4,c=(15&n)<<2|r>>6,d=63&r,isNaN(n)?c=d=64:isNaN(r)&&(d=64),a=a+this.keyStr.charAt(o)+this.keyStr.charAt(i)+this.keyStr.charAt(c)+this.keyStr.charAt(d);return a},decode:function(e){var t,n,r,o,i,c,d,a="",s=0;for(e=e.replace(/[^A-Za-z0-9\+\/\=]/g,"");s<e.length;)o=this.keyStr.indexOf(e.charAt(s++)),i=this.keyStr.indexOf(e.charAt(s++)),c=this.keyStr.indexOf(e.charAt(s++)),d=this.keyStr.indexOf(e.charAt(s++)),t=o<<2|i>>4,n=(15&i)<<4|c>>2,r=(3&c)<<6|d,a+=String.fromCharCode(t),64!=c&&(a+=String.fromCharCode(n)),64!=d&&(a+=String.fromCharCode(r));return a=this.utf8Decode(a)},utf8Encode:function(e){e=e.replace(/\r\n/g,"\n");for(var t="",n=0;n<e.length;n++){var r=e.charCodeAt(n);128>r?t+=String.fromCharCode(r):r>127&&2048>r?(t+=String.fromCharCode(r>>6|192),t+=String.fromCharCode(63&r|128)):(t+=String.fromCharCode(r>>12|224),t+=String.fromCharCode(r>>6&63|128),t+=String.fromCharCode(63&r|128))}return t},utf8Decode:function(e){for(var t="",n=0,r=0,o=0,i=0;n<e.length;)r=e.charCodeAt(n),128>r?(t+=String.fromCharCode(r),n++):r>191&&224>r?(o=e.charCodeAt(n+1),t+=String.fromCharCode((31&r)<<6|63&o),n+=2):(o=e.charCodeAt(n+1),i=e.charCodeAt(n+2),t+=String.fromCharCode((15&r)<<12|(63&o)<<6|63&i),n+=3);return t}}},getCachedIds:function(e){var n=null;if(!n&&window.sessionStorage&&(n=window.sessionStorage.getItem("__ansync3rdp_"+e)),!n&&window.localStorage&&(n=window.localStorage.getItem("__ansync3rdp_"+e)),n)try{n=JSON.parse(this.Util.Base64.decode(n))}catch(r){n=null,"undefined"!=typeof console,t(r,"AnSync3rdParty::getCachedIds")}return n},getCachedIdsEnc:function(){var e=this.getCachedIds(this.params.criBidderId),n=null;try{e&&e.uCode?(n={tpuids:[{provider:e.bId,user_id:e.uCode}]},n=this.Util.Base64.encode(JSON.stringify(n))):n=null}catch(r){n=null,"undefined"!=typeof console,t(r,"AnSync3rdParty::getCachedIdsEnc")}return n},setCachedIds:function(e,n){var r=null;try{r={bId:e,uCode:n,ts:new Date},r=this.Util.Base64.encode(JSON.stringify(r))}catch(o){"undefined"!=typeof console,t(o,"AnSync3rdParty::setCachedIds")}window.sessionStorage&&window.sessionStorage.setItem("__ansync3rdp_"+e,r),window.localStorage&&window.localStorage.setItem("__ansync3rdp_"+e,r)},isStaleCachedIds:function(e){var n=!0;if(e&&"string"==typeof e.ts)try{var r=new Date-new Date(e.ts);n=r>this.params.idsStaleMs,"undefined"!=typeof console}catch(o){n=!0,"undefined"!=typeof console,t(o,"AnSync3rdParty::isStaleCachedIds")}return n},criteoMakeSyncCb:function(){var e=this;return function(t){"undefined"!=typeof console,e.setCachedIds(e.params.criBidderId,"string"==typeof t.userid&&""!==t.userid?t.userid:null)}},criteoSchdAsync:function(e,t){"undefined"!=typeof console,window[e]=t;var n=document.createElement("script");n.type="text/javascript",n.async=!0,n.src="https://gum.criteo.com/sync?c="+this.params.criId+"&r=2&j="+e;var r=document.getElementsByTagName("head")||document.getElementsByTagName("body");r&&r[0]&&r[0].appendChild(n)},sync:function(){var e=this.getCachedIds(this.params.criId);this.isStaleCachedIds(e)&&this.criteoSchdAsync(this.params.criteoFun,this.criteoMakeSyncCb());var t=this.getCachedIdsEnc();return s=t?this.params.ids+"="+t:""}};var a=function(n){var r="";try{n=e(n,2);var o=e(new d(n),3);r=o.sync()}catch(i){r="","undefined"!=typeof console,t(i,"AnSync3rdParty::executeSync")}return r};;var s="http://g.adnxs.com/ttj?ttjb=1&bdc=1455180422&bdh=J6gjDJfnSvoDrTDA3q5SzDh6LlI.";s+="&"+a({idsStaleSec:600,criBidderId:"criteo",criId:"30",ids:"tpuids",criteoFun:"cr_handle_data_a"}),s+=c({iv:"view_iv",pos:"view_pos",ws:"view_ws",vs:"view_vs"}),s+="&"+o({rdRef:"bdref",rdTop:"bdtop",rdIfs:"bdifs",rdStk:"bstk",rdQs:"&id=3930419&size=728x90&pt1=sid%3D51962%26m%3D1%26tp%3D5%26d%3Dj%26t%3Dn%26vcm_acv%3D1.1%26version%3D1.4%26c%3D0.4554753476626233%26vcm_ifr%3D1%26vcm_xy%3D-1..-1%26vcm_vv%3Dtrue%26vcm_vm%3Dfalse%26vcm_pr%3Dhttp%253A%2F%2Fwww.yolinux.com%2FADVERTISING%2Fiframe728x90px-ValueClick.html%26vcm_tr%3D%26vcm_cr%3D%26ud%3DCSBCT12OzJg-EQAAAAAAAAAAGQAAAAAAAAAAIS1DHOviNvo_KAAwAGiElfG1BXACiAHJ4HyQAZnmJJgB_pUDoAEBqAEF8AIB&pt2=mj4ama&cb=1455180421075"}),n(s)}();