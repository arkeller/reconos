
unsigned long dcr_read(int dcrn)
{
	switch(dcrn){
		case 0:
			__asm__("mfdcr 3,0");
			break;
		case 1:
			__asm__("mfdcr 3,1");
			break;
		case 2:
			__asm__("mfdcr 3,2");
			break;
		case 3:
			__asm__("mfdcr 3,3");
			break;
		case 4:
			__asm__("mfdcr 3,4");
			break;
		case 5:
			__asm__("mfdcr 3,5");
			break;
		case 6:
			__asm__("mfdcr 3,6");
			break;
		case 7:
			__asm__("mfdcr 3,7");
			break;
		case 8:
			__asm__("mfdcr 3,8");
			break;
		case 9:
			__asm__("mfdcr 3,9");
			break;
		case 10:
			__asm__("mfdcr 3,10");
			break;
		case 11:
			__asm__("mfdcr 3,11");
			break;
		case 12:
			__asm__("mfdcr 3,12");
			break;
		case 13:
			__asm__("mfdcr 3,13");
			break;
		case 14:
			__asm__("mfdcr 3,14");
			break;
		case 15:
			__asm__("mfdcr 3,15");
			break;
		case 16:
			__asm__("mfdcr 3,16");
			break;
		case 17:
			__asm__("mfdcr 3,17");
			break;
		case 18:
			__asm__("mfdcr 3,18");
			break;
		case 19:
			__asm__("mfdcr 3,19");
			break;
		case 20:
			__asm__("mfdcr 3,20");
			break;
		case 21:
			__asm__("mfdcr 3,21");
			break;
		case 22:
			__asm__("mfdcr 3,22");
			break;
		case 23:
			__asm__("mfdcr 3,23");
			break;
		case 24:
			__asm__("mfdcr 3,24");
			break;
		case 25:
			__asm__("mfdcr 3,25");
			break;
		case 26:
			__asm__("mfdcr 3,26");
			break;
		case 27:
			__asm__("mfdcr 3,27");
			break;
		case 28:
			__asm__("mfdcr 3,28");
			break;
		case 29:
			__asm__("mfdcr 3,29");
			break;
		case 30:
			__asm__("mfdcr 3,30");
			break;
		case 31:
			__asm__("mfdcr 3,31");
			break;
		case 32:
			__asm__("mfdcr 3,32");
			break;
		case 33:
			__asm__("mfdcr 3,33");
			break;
		case 34:
			__asm__("mfdcr 3,34");
			break;
		case 35:
			__asm__("mfdcr 3,35");
			break;
		case 36:
			__asm__("mfdcr 3,36");
			break;
		case 37:
			__asm__("mfdcr 3,37");
			break;
		case 38:
			__asm__("mfdcr 3,38");
			break;
		case 39:
			__asm__("mfdcr 3,39");
			break;
		case 40:
			__asm__("mfdcr 3,40");
			break;
		case 41:
			__asm__("mfdcr 3,41");
			break;
		case 42:
			__asm__("mfdcr 3,42");
			break;
		case 43:
			__asm__("mfdcr 3,43");
			break;
		case 44:
			__asm__("mfdcr 3,44");
			break;
		case 45:
			__asm__("mfdcr 3,45");
			break;
		case 46:
			__asm__("mfdcr 3,46");
			break;
		case 47:
			__asm__("mfdcr 3,47");
			break;
		case 48:
			__asm__("mfdcr 3,48");
			break;
		case 49:
			__asm__("mfdcr 3,49");
			break;
		case 50:
			__asm__("mfdcr 3,50");
			break;
		case 51:
			__asm__("mfdcr 3,51");
			break;
		case 52:
			__asm__("mfdcr 3,52");
			break;
		case 53:
			__asm__("mfdcr 3,53");
			break;
		case 54:
			__asm__("mfdcr 3,54");
			break;
		case 55:
			__asm__("mfdcr 3,55");
			break;
		case 56:
			__asm__("mfdcr 3,56");
			break;
		case 57:
			__asm__("mfdcr 3,57");
			break;
		case 58:
			__asm__("mfdcr 3,58");
			break;
		case 59:
			__asm__("mfdcr 3,59");
			break;
		case 60:
			__asm__("mfdcr 3,60");
			break;
		case 61:
			__asm__("mfdcr 3,61");
			break;
		case 62:
			__asm__("mfdcr 3,62");
			break;
		case 63:
			__asm__("mfdcr 3,63");
			break;
		case 64:
			__asm__("mfdcr 3,64");
			break;
		case 65:
			__asm__("mfdcr 3,65");
			break;
		case 66:
			__asm__("mfdcr 3,66");
			break;
		case 67:
			__asm__("mfdcr 3,67");
			break;
		case 68:
			__asm__("mfdcr 3,68");
			break;
		case 69:
			__asm__("mfdcr 3,69");
			break;
		case 70:
			__asm__("mfdcr 3,70");
			break;
		case 71:
			__asm__("mfdcr 3,71");
			break;
		case 72:
			__asm__("mfdcr 3,72");
			break;
		case 73:
			__asm__("mfdcr 3,73");
			break;
		case 74:
			__asm__("mfdcr 3,74");
			break;
		case 75:
			__asm__("mfdcr 3,75");
			break;
		case 76:
			__asm__("mfdcr 3,76");
			break;
		case 77:
			__asm__("mfdcr 3,77");
			break;
		case 78:
			__asm__("mfdcr 3,78");
			break;
		case 79:
			__asm__("mfdcr 3,79");
			break;
		case 80:
			__asm__("mfdcr 3,80");
			break;
		case 81:
			__asm__("mfdcr 3,81");
			break;
		case 82:
			__asm__("mfdcr 3,82");
			break;
		case 83:
			__asm__("mfdcr 3,83");
			break;
		case 84:
			__asm__("mfdcr 3,84");
			break;
		case 85:
			__asm__("mfdcr 3,85");
			break;
		case 86:
			__asm__("mfdcr 3,86");
			break;
		case 87:
			__asm__("mfdcr 3,87");
			break;
		case 88:
			__asm__("mfdcr 3,88");
			break;
		case 89:
			__asm__("mfdcr 3,89");
			break;
		case 90:
			__asm__("mfdcr 3,90");
			break;
		case 91:
			__asm__("mfdcr 3,91");
			break;
		case 92:
			__asm__("mfdcr 3,92");
			break;
		case 93:
			__asm__("mfdcr 3,93");
			break;
		case 94:
			__asm__("mfdcr 3,94");
			break;
		case 95:
			__asm__("mfdcr 3,95");
			break;
		case 96:
			__asm__("mfdcr 3,96");
			break;
		case 97:
			__asm__("mfdcr 3,97");
			break;
		case 98:
			__asm__("mfdcr 3,98");
			break;
		case 99:
			__asm__("mfdcr 3,99");
			break;
		case 100:
			__asm__("mfdcr 3,100");
			break;
		case 101:
			__asm__("mfdcr 3,101");
			break;
		case 102:
			__asm__("mfdcr 3,102");
			break;
		case 103:
			__asm__("mfdcr 3,103");
			break;
		case 104:
			__asm__("mfdcr 3,104");
			break;
		case 105:
			__asm__("mfdcr 3,105");
			break;
		case 106:
			__asm__("mfdcr 3,106");
			break;
		case 107:
			__asm__("mfdcr 3,107");
			break;
		case 108:
			__asm__("mfdcr 3,108");
			break;
		case 109:
			__asm__("mfdcr 3,109");
			break;
		case 110:
			__asm__("mfdcr 3,110");
			break;
		case 111:
			__asm__("mfdcr 3,111");
			break;
		case 112:
			__asm__("mfdcr 3,112");
			break;
		case 113:
			__asm__("mfdcr 3,113");
			break;
		case 114:
			__asm__("mfdcr 3,114");
			break;
		case 115:
			__asm__("mfdcr 3,115");
			break;
		case 116:
			__asm__("mfdcr 3,116");
			break;
		case 117:
			__asm__("mfdcr 3,117");
			break;
		case 118:
			__asm__("mfdcr 3,118");
			break;
		case 119:
			__asm__("mfdcr 3,119");
			break;
		case 120:
			__asm__("mfdcr 3,120");
			break;
		case 121:
			__asm__("mfdcr 3,121");
			break;
		case 122:
			__asm__("mfdcr 3,122");
			break;
		case 123:
			__asm__("mfdcr 3,123");
			break;
		case 124:
			__asm__("mfdcr 3,124");
			break;
		case 125:
			__asm__("mfdcr 3,125");
			break;
		case 126:
			__asm__("mfdcr 3,126");
			break;
		case 127:
			__asm__("mfdcr 3,127");
			break;
		case 128:
			__asm__("mfdcr 3,128");
			break;
		case 129:
			__asm__("mfdcr 3,129");
			break;
		case 130:
			__asm__("mfdcr 3,130");
			break;
		case 131:
			__asm__("mfdcr 3,131");
			break;
		case 132:
			__asm__("mfdcr 3,132");
			break;
		case 133:
			__asm__("mfdcr 3,133");
			break;
		case 134:
			__asm__("mfdcr 3,134");
			break;
		case 135:
			__asm__("mfdcr 3,135");
			break;
		case 136:
			__asm__("mfdcr 3,136");
			break;
		case 137:
			__asm__("mfdcr 3,137");
			break;
		case 138:
			__asm__("mfdcr 3,138");
			break;
		case 139:
			__asm__("mfdcr 3,139");
			break;
		case 140:
			__asm__("mfdcr 3,140");
			break;
		case 141:
			__asm__("mfdcr 3,141");
			break;
		case 142:
			__asm__("mfdcr 3,142");
			break;
		case 143:
			__asm__("mfdcr 3,143");
			break;
		case 144:
			__asm__("mfdcr 3,144");
			break;
		case 145:
			__asm__("mfdcr 3,145");
			break;
		case 146:
			__asm__("mfdcr 3,146");
			break;
		case 147:
			__asm__("mfdcr 3,147");
			break;
		case 148:
			__asm__("mfdcr 3,148");
			break;
		case 149:
			__asm__("mfdcr 3,149");
			break;
		case 150:
			__asm__("mfdcr 3,150");
			break;
		case 151:
			__asm__("mfdcr 3,151");
			break;
		case 152:
			__asm__("mfdcr 3,152");
			break;
		case 153:
			__asm__("mfdcr 3,153");
			break;
		case 154:
			__asm__("mfdcr 3,154");
			break;
		case 155:
			__asm__("mfdcr 3,155");
			break;
		case 156:
			__asm__("mfdcr 3,156");
			break;
		case 157:
			__asm__("mfdcr 3,157");
			break;
		case 158:
			__asm__("mfdcr 3,158");
			break;
		case 159:
			__asm__("mfdcr 3,159");
			break;
		case 160:
			__asm__("mfdcr 3,160");
			break;
		case 161:
			__asm__("mfdcr 3,161");
			break;
		case 162:
			__asm__("mfdcr 3,162");
			break;
		case 163:
			__asm__("mfdcr 3,163");
			break;
		case 164:
			__asm__("mfdcr 3,164");
			break;
		case 165:
			__asm__("mfdcr 3,165");
			break;
		case 166:
			__asm__("mfdcr 3,166");
			break;
		case 167:
			__asm__("mfdcr 3,167");
			break;
		case 168:
			__asm__("mfdcr 3,168");
			break;
		case 169:
			__asm__("mfdcr 3,169");
			break;
		case 170:
			__asm__("mfdcr 3,170");
			break;
		case 171:
			__asm__("mfdcr 3,171");
			break;
		case 172:
			__asm__("mfdcr 3,172");
			break;
		case 173:
			__asm__("mfdcr 3,173");
			break;
		case 174:
			__asm__("mfdcr 3,174");
			break;
		case 175:
			__asm__("mfdcr 3,175");
			break;
		case 176:
			__asm__("mfdcr 3,176");
			break;
		case 177:
			__asm__("mfdcr 3,177");
			break;
		case 178:
			__asm__("mfdcr 3,178");
			break;
		case 179:
			__asm__("mfdcr 3,179");
			break;
		case 180:
			__asm__("mfdcr 3,180");
			break;
		case 181:
			__asm__("mfdcr 3,181");
			break;
		case 182:
			__asm__("mfdcr 3,182");
			break;
		case 183:
			__asm__("mfdcr 3,183");
			break;
		case 184:
			__asm__("mfdcr 3,184");
			break;
		case 185:
			__asm__("mfdcr 3,185");
			break;
		case 186:
			__asm__("mfdcr 3,186");
			break;
		case 187:
			__asm__("mfdcr 3,187");
			break;
		case 188:
			__asm__("mfdcr 3,188");
			break;
		case 189:
			__asm__("mfdcr 3,189");
			break;
		case 190:
			__asm__("mfdcr 3,190");
			break;
		case 191:
			__asm__("mfdcr 3,191");
			break;
		case 192:
			__asm__("mfdcr 3,192");
			break;
		case 193:
			__asm__("mfdcr 3,193");
			break;
		case 194:
			__asm__("mfdcr 3,194");
			break;
		case 195:
			__asm__("mfdcr 3,195");
			break;
		case 196:
			__asm__("mfdcr 3,196");
			break;
		case 197:
			__asm__("mfdcr 3,197");
			break;
		case 198:
			__asm__("mfdcr 3,198");
			break;
		case 199:
			__asm__("mfdcr 3,199");
			break;
		case 200:
			__asm__("mfdcr 3,200");
			break;
		case 201:
			__asm__("mfdcr 3,201");
			break;
		case 202:
			__asm__("mfdcr 3,202");
			break;
		case 203:
			__asm__("mfdcr 3,203");
			break;
		case 204:
			__asm__("mfdcr 3,204");
			break;
		case 205:
			__asm__("mfdcr 3,205");
			break;
		case 206:
			__asm__("mfdcr 3,206");
			break;
		case 207:
			__asm__("mfdcr 3,207");
			break;
		case 208:
			__asm__("mfdcr 3,208");
			break;
		case 209:
			__asm__("mfdcr 3,209");
			break;
		case 210:
			__asm__("mfdcr 3,210");
			break;
		case 211:
			__asm__("mfdcr 3,211");
			break;
		case 212:
			__asm__("mfdcr 3,212");
			break;
		case 213:
			__asm__("mfdcr 3,213");
			break;
		case 214:
			__asm__("mfdcr 3,214");
			break;
		case 215:
			__asm__("mfdcr 3,215");
			break;
		case 216:
			__asm__("mfdcr 3,216");
			break;
		case 217:
			__asm__("mfdcr 3,217");
			break;
		case 218:
			__asm__("mfdcr 3,218");
			break;
		case 219:
			__asm__("mfdcr 3,219");
			break;
		case 220:
			__asm__("mfdcr 3,220");
			break;
		case 221:
			__asm__("mfdcr 3,221");
			break;
		case 222:
			__asm__("mfdcr 3,222");
			break;
		case 223:
			__asm__("mfdcr 3,223");
			break;
		case 224:
			__asm__("mfdcr 3,224");
			break;
		case 225:
			__asm__("mfdcr 3,225");
			break;
		case 226:
			__asm__("mfdcr 3,226");
			break;
		case 227:
			__asm__("mfdcr 3,227");
			break;
		case 228:
			__asm__("mfdcr 3,228");
			break;
		case 229:
			__asm__("mfdcr 3,229");
			break;
		case 230:
			__asm__("mfdcr 3,230");
			break;
		case 231:
			__asm__("mfdcr 3,231");
			break;
		case 232:
			__asm__("mfdcr 3,232");
			break;
		case 233:
			__asm__("mfdcr 3,233");
			break;
		case 234:
			__asm__("mfdcr 3,234");
			break;
		case 235:
			__asm__("mfdcr 3,235");
			break;
		case 236:
			__asm__("mfdcr 3,236");
			break;
		case 237:
			__asm__("mfdcr 3,237");
			break;
		case 238:
			__asm__("mfdcr 3,238");
			break;
		case 239:
			__asm__("mfdcr 3,239");
			break;
		case 240:
			__asm__("mfdcr 3,240");
			break;
		case 241:
			__asm__("mfdcr 3,241");
			break;
		case 242:
			__asm__("mfdcr 3,242");
			break;
		case 243:
			__asm__("mfdcr 3,243");
			break;
		case 244:
			__asm__("mfdcr 3,244");
			break;
		case 245:
			__asm__("mfdcr 3,245");
			break;
		case 246:
			__asm__("mfdcr 3,246");
			break;
		case 247:
			__asm__("mfdcr 3,247");
			break;
		case 248:
			__asm__("mfdcr 3,248");
			break;
		case 249:
			__asm__("mfdcr 3,249");
			break;
		case 250:
			__asm__("mfdcr 3,250");
			break;
		case 251:
			__asm__("mfdcr 3,251");
			break;
		case 252:
			__asm__("mfdcr 3,252");
			break;
		case 253:
			__asm__("mfdcr 3,253");
			break;
		case 254:
			__asm__("mfdcr 3,254");
			break;
		case 255:
			__asm__("mfdcr 3,255");
			break;
		case 256:
			__asm__("mfdcr 3,256");
			break;
		case 257:
			__asm__("mfdcr 3,257");
			break;
		case 258:
			__asm__("mfdcr 3,258");
			break;
		case 259:
			__asm__("mfdcr 3,259");
			break;
		case 260:
			__asm__("mfdcr 3,260");
			break;
		case 261:
			__asm__("mfdcr 3,261");
			break;
		case 262:
			__asm__("mfdcr 3,262");
			break;
		case 263:
			__asm__("mfdcr 3,263");
			break;
		case 264:
			__asm__("mfdcr 3,264");
			break;
		case 265:
			__asm__("mfdcr 3,265");
			break;
		case 266:
			__asm__("mfdcr 3,266");
			break;
		case 267:
			__asm__("mfdcr 3,267");
			break;
		case 268:
			__asm__("mfdcr 3,268");
			break;
		case 269:
			__asm__("mfdcr 3,269");
			break;
		case 270:
			__asm__("mfdcr 3,270");
			break;
		case 271:
			__asm__("mfdcr 3,271");
			break;
		case 272:
			__asm__("mfdcr 3,272");
			break;
		case 273:
			__asm__("mfdcr 3,273");
			break;
		case 274:
			__asm__("mfdcr 3,274");
			break;
		case 275:
			__asm__("mfdcr 3,275");
			break;
		case 276:
			__asm__("mfdcr 3,276");
			break;
		case 277:
			__asm__("mfdcr 3,277");
			break;
		case 278:
			__asm__("mfdcr 3,278");
			break;
		case 279:
			__asm__("mfdcr 3,279");
			break;
		case 280:
			__asm__("mfdcr 3,280");
			break;
		case 281:
			__asm__("mfdcr 3,281");
			break;
		case 282:
			__asm__("mfdcr 3,282");
			break;
		case 283:
			__asm__("mfdcr 3,283");
			break;
		case 284:
			__asm__("mfdcr 3,284");
			break;
		case 285:
			__asm__("mfdcr 3,285");
			break;
		case 286:
			__asm__("mfdcr 3,286");
			break;
		case 287:
			__asm__("mfdcr 3,287");
			break;
		case 288:
			__asm__("mfdcr 3,288");
			break;
		case 289:
			__asm__("mfdcr 3,289");
			break;
		case 290:
			__asm__("mfdcr 3,290");
			break;
		case 291:
			__asm__("mfdcr 3,291");
			break;
		case 292:
			__asm__("mfdcr 3,292");
			break;
		case 293:
			__asm__("mfdcr 3,293");
			break;
		case 294:
			__asm__("mfdcr 3,294");
			break;
		case 295:
			__asm__("mfdcr 3,295");
			break;
		case 296:
			__asm__("mfdcr 3,296");
			break;
		case 297:
			__asm__("mfdcr 3,297");
			break;
		case 298:
			__asm__("mfdcr 3,298");
			break;
		case 299:
			__asm__("mfdcr 3,299");
			break;
		case 300:
			__asm__("mfdcr 3,300");
			break;
		case 301:
			__asm__("mfdcr 3,301");
			break;
		case 302:
			__asm__("mfdcr 3,302");
			break;
		case 303:
			__asm__("mfdcr 3,303");
			break;
		case 304:
			__asm__("mfdcr 3,304");
			break;
		case 305:
			__asm__("mfdcr 3,305");
			break;
		case 306:
			__asm__("mfdcr 3,306");
			break;
		case 307:
			__asm__("mfdcr 3,307");
			break;
		case 308:
			__asm__("mfdcr 3,308");
			break;
		case 309:
			__asm__("mfdcr 3,309");
			break;
		case 310:
			__asm__("mfdcr 3,310");
			break;
		case 311:
			__asm__("mfdcr 3,311");
			break;
		case 312:
			__asm__("mfdcr 3,312");
			break;
		case 313:
			__asm__("mfdcr 3,313");
			break;
		case 314:
			__asm__("mfdcr 3,314");
			break;
		case 315:
			__asm__("mfdcr 3,315");
			break;
		case 316:
			__asm__("mfdcr 3,316");
			break;
		case 317:
			__asm__("mfdcr 3,317");
			break;
		case 318:
			__asm__("mfdcr 3,318");
			break;
		case 319:
			__asm__("mfdcr 3,319");
			break;
		case 320:
			__asm__("mfdcr 3,320");
			break;
		case 321:
			__asm__("mfdcr 3,321");
			break;
		case 322:
			__asm__("mfdcr 3,322");
			break;
		case 323:
			__asm__("mfdcr 3,323");
			break;
		case 324:
			__asm__("mfdcr 3,324");
			break;
		case 325:
			__asm__("mfdcr 3,325");
			break;
		case 326:
			__asm__("mfdcr 3,326");
			break;
		case 327:
			__asm__("mfdcr 3,327");
			break;
		case 328:
			__asm__("mfdcr 3,328");
			break;
		case 329:
			__asm__("mfdcr 3,329");
			break;
		case 330:
			__asm__("mfdcr 3,330");
			break;
		case 331:
			__asm__("mfdcr 3,331");
			break;
		case 332:
			__asm__("mfdcr 3,332");
			break;
		case 333:
			__asm__("mfdcr 3,333");
			break;
		case 334:
			__asm__("mfdcr 3,334");
			break;
		case 335:
			__asm__("mfdcr 3,335");
			break;
		case 336:
			__asm__("mfdcr 3,336");
			break;
		case 337:
			__asm__("mfdcr 3,337");
			break;
		case 338:
			__asm__("mfdcr 3,338");
			break;
		case 339:
			__asm__("mfdcr 3,339");
			break;
		case 340:
			__asm__("mfdcr 3,340");
			break;
		case 341:
			__asm__("mfdcr 3,341");
			break;
		case 342:
			__asm__("mfdcr 3,342");
			break;
		case 343:
			__asm__("mfdcr 3,343");
			break;
		case 344:
			__asm__("mfdcr 3,344");
			break;
		case 345:
			__asm__("mfdcr 3,345");
			break;
		case 346:
			__asm__("mfdcr 3,346");
			break;
		case 347:
			__asm__("mfdcr 3,347");
			break;
		case 348:
			__asm__("mfdcr 3,348");
			break;
		case 349:
			__asm__("mfdcr 3,349");
			break;
		case 350:
			__asm__("mfdcr 3,350");
			break;
		case 351:
			__asm__("mfdcr 3,351");
			break;
		case 352:
			__asm__("mfdcr 3,352");
			break;
		case 353:
			__asm__("mfdcr 3,353");
			break;
		case 354:
			__asm__("mfdcr 3,354");
			break;
		case 355:
			__asm__("mfdcr 3,355");
			break;
		case 356:
			__asm__("mfdcr 3,356");
			break;
		case 357:
			__asm__("mfdcr 3,357");
			break;
		case 358:
			__asm__("mfdcr 3,358");
			break;
		case 359:
			__asm__("mfdcr 3,359");
			break;
		case 360:
			__asm__("mfdcr 3,360");
			break;
		case 361:
			__asm__("mfdcr 3,361");
			break;
		case 362:
			__asm__("mfdcr 3,362");
			break;
		case 363:
			__asm__("mfdcr 3,363");
			break;
		case 364:
			__asm__("mfdcr 3,364");
			break;
		case 365:
			__asm__("mfdcr 3,365");
			break;
		case 366:
			__asm__("mfdcr 3,366");
			break;
		case 367:
			__asm__("mfdcr 3,367");
			break;
		case 368:
			__asm__("mfdcr 3,368");
			break;
		case 369:
			__asm__("mfdcr 3,369");
			break;
		case 370:
			__asm__("mfdcr 3,370");
			break;
		case 371:
			__asm__("mfdcr 3,371");
			break;
		case 372:
			__asm__("mfdcr 3,372");
			break;
		case 373:
			__asm__("mfdcr 3,373");
			break;
		case 374:
			__asm__("mfdcr 3,374");
			break;
		case 375:
			__asm__("mfdcr 3,375");
			break;
		case 376:
			__asm__("mfdcr 3,376");
			break;
		case 377:
			__asm__("mfdcr 3,377");
			break;
		case 378:
			__asm__("mfdcr 3,378");
			break;
		case 379:
			__asm__("mfdcr 3,379");
			break;
		case 380:
			__asm__("mfdcr 3,380");
			break;
		case 381:
			__asm__("mfdcr 3,381");
			break;
		case 382:
			__asm__("mfdcr 3,382");
			break;
		case 383:
			__asm__("mfdcr 3,383");
			break;
		case 384:
			__asm__("mfdcr 3,384");
			break;
		case 385:
			__asm__("mfdcr 3,385");
			break;
		case 386:
			__asm__("mfdcr 3,386");
			break;
		case 387:
			__asm__("mfdcr 3,387");
			break;
		case 388:
			__asm__("mfdcr 3,388");
			break;
		case 389:
			__asm__("mfdcr 3,389");
			break;
		case 390:
			__asm__("mfdcr 3,390");
			break;
		case 391:
			__asm__("mfdcr 3,391");
			break;
		case 392:
			__asm__("mfdcr 3,392");
			break;
		case 393:
			__asm__("mfdcr 3,393");
			break;
		case 394:
			__asm__("mfdcr 3,394");
			break;
		case 395:
			__asm__("mfdcr 3,395");
			break;
		case 396:
			__asm__("mfdcr 3,396");
			break;
		case 397:
			__asm__("mfdcr 3,397");
			break;
		case 398:
			__asm__("mfdcr 3,398");
			break;
		case 399:
			__asm__("mfdcr 3,399");
			break;
		case 400:
			__asm__("mfdcr 3,400");
			break;
		case 401:
			__asm__("mfdcr 3,401");
			break;
		case 402:
			__asm__("mfdcr 3,402");
			break;
		case 403:
			__asm__("mfdcr 3,403");
			break;
		case 404:
			__asm__("mfdcr 3,404");
			break;
		case 405:
			__asm__("mfdcr 3,405");
			break;
		case 406:
			__asm__("mfdcr 3,406");
			break;
		case 407:
			__asm__("mfdcr 3,407");
			break;
		case 408:
			__asm__("mfdcr 3,408");
			break;
		case 409:
			__asm__("mfdcr 3,409");
			break;
		case 410:
			__asm__("mfdcr 3,410");
			break;
		case 411:
			__asm__("mfdcr 3,411");
			break;
		case 412:
			__asm__("mfdcr 3,412");
			break;
		case 413:
			__asm__("mfdcr 3,413");
			break;
		case 414:
			__asm__("mfdcr 3,414");
			break;
		case 415:
			__asm__("mfdcr 3,415");
			break;
		case 416:
			__asm__("mfdcr 3,416");
			break;
		case 417:
			__asm__("mfdcr 3,417");
			break;
		case 418:
			__asm__("mfdcr 3,418");
			break;
		case 419:
			__asm__("mfdcr 3,419");
			break;
		case 420:
			__asm__("mfdcr 3,420");
			break;
		case 421:
			__asm__("mfdcr 3,421");
			break;
		case 422:
			__asm__("mfdcr 3,422");
			break;
		case 423:
			__asm__("mfdcr 3,423");
			break;
		case 424:
			__asm__("mfdcr 3,424");
			break;
		case 425:
			__asm__("mfdcr 3,425");
			break;
		case 426:
			__asm__("mfdcr 3,426");
			break;
		case 427:
			__asm__("mfdcr 3,427");
			break;
		case 428:
			__asm__("mfdcr 3,428");
			break;
		case 429:
			__asm__("mfdcr 3,429");
			break;
		case 430:
			__asm__("mfdcr 3,430");
			break;
		case 431:
			__asm__("mfdcr 3,431");
			break;
		case 432:
			__asm__("mfdcr 3,432");
			break;
		case 433:
			__asm__("mfdcr 3,433");
			break;
		case 434:
			__asm__("mfdcr 3,434");
			break;
		case 435:
			__asm__("mfdcr 3,435");
			break;
		case 436:
			__asm__("mfdcr 3,436");
			break;
		case 437:
			__asm__("mfdcr 3,437");
			break;
		case 438:
			__asm__("mfdcr 3,438");
			break;
		case 439:
			__asm__("mfdcr 3,439");
			break;
		case 440:
			__asm__("mfdcr 3,440");
			break;
		case 441:
			__asm__("mfdcr 3,441");
			break;
		case 442:
			__asm__("mfdcr 3,442");
			break;
		case 443:
			__asm__("mfdcr 3,443");
			break;
		case 444:
			__asm__("mfdcr 3,444");
			break;
		case 445:
			__asm__("mfdcr 3,445");
			break;
		case 446:
			__asm__("mfdcr 3,446");
			break;
		case 447:
			__asm__("mfdcr 3,447");
			break;
		case 448:
			__asm__("mfdcr 3,448");
			break;
		case 449:
			__asm__("mfdcr 3,449");
			break;
		case 450:
			__asm__("mfdcr 3,450");
			break;
		case 451:
			__asm__("mfdcr 3,451");
			break;
		case 452:
			__asm__("mfdcr 3,452");
			break;
		case 453:
			__asm__("mfdcr 3,453");
			break;
		case 454:
			__asm__("mfdcr 3,454");
			break;
		case 455:
			__asm__("mfdcr 3,455");
			break;
		case 456:
			__asm__("mfdcr 3,456");
			break;
		case 457:
			__asm__("mfdcr 3,457");
			break;
		case 458:
			__asm__("mfdcr 3,458");
			break;
		case 459:
			__asm__("mfdcr 3,459");
			break;
		case 460:
			__asm__("mfdcr 3,460");
			break;
		case 461:
			__asm__("mfdcr 3,461");
			break;
		case 462:
			__asm__("mfdcr 3,462");
			break;
		case 463:
			__asm__("mfdcr 3,463");
			break;
		case 464:
			__asm__("mfdcr 3,464");
			break;
		case 465:
			__asm__("mfdcr 3,465");
			break;
		case 466:
			__asm__("mfdcr 3,466");
			break;
		case 467:
			__asm__("mfdcr 3,467");
			break;
		case 468:
			__asm__("mfdcr 3,468");
			break;
		case 469:
			__asm__("mfdcr 3,469");
			break;
		case 470:
			__asm__("mfdcr 3,470");
			break;
		case 471:
			__asm__("mfdcr 3,471");
			break;
		case 472:
			__asm__("mfdcr 3,472");
			break;
		case 473:
			__asm__("mfdcr 3,473");
			break;
		case 474:
			__asm__("mfdcr 3,474");
			break;
		case 475:
			__asm__("mfdcr 3,475");
			break;
		case 476:
			__asm__("mfdcr 3,476");
			break;
		case 477:
			__asm__("mfdcr 3,477");
			break;
		case 478:
			__asm__("mfdcr 3,478");
			break;
		case 479:
			__asm__("mfdcr 3,479");
			break;
		case 480:
			__asm__("mfdcr 3,480");
			break;
		case 481:
			__asm__("mfdcr 3,481");
			break;
		case 482:
			__asm__("mfdcr 3,482");
			break;
		case 483:
			__asm__("mfdcr 3,483");
			break;
		case 484:
			__asm__("mfdcr 3,484");
			break;
		case 485:
			__asm__("mfdcr 3,485");
			break;
		case 486:
			__asm__("mfdcr 3,486");
			break;
		case 487:
			__asm__("mfdcr 3,487");
			break;
		case 488:
			__asm__("mfdcr 3,488");
			break;
		case 489:
			__asm__("mfdcr 3,489");
			break;
		case 490:
			__asm__("mfdcr 3,490");
			break;
		case 491:
			__asm__("mfdcr 3,491");
			break;
		case 492:
			__asm__("mfdcr 3,492");
			break;
		case 493:
			__asm__("mfdcr 3,493");
			break;
		case 494:
			__asm__("mfdcr 3,494");
			break;
		case 495:
			__asm__("mfdcr 3,495");
			break;
		case 496:
			__asm__("mfdcr 3,496");
			break;
		case 497:
			__asm__("mfdcr 3,497");
			break;
		case 498:
			__asm__("mfdcr 3,498");
			break;
		case 499:
			__asm__("mfdcr 3,499");
			break;
		case 500:
			__asm__("mfdcr 3,500");
			break;
		case 501:
			__asm__("mfdcr 3,501");
			break;
		case 502:
			__asm__("mfdcr 3,502");
			break;
		case 503:
			__asm__("mfdcr 3,503");
			break;
		case 504:
			__asm__("mfdcr 3,504");
			break;
		case 505:
			__asm__("mfdcr 3,505");
			break;
		case 506:
			__asm__("mfdcr 3,506");
			break;
		case 507:
			__asm__("mfdcr 3,507");
			break;
		case 508:
			__asm__("mfdcr 3,508");
			break;
		case 509:
			__asm__("mfdcr 3,509");
			break;
		case 510:
			__asm__("mfdcr 3,510");
			break;
		case 511:
			__asm__("mfdcr 3,511");
			break;
		case 512:
			__asm__("mfdcr 3,512");
			break;
		case 513:
			__asm__("mfdcr 3,513");
			break;
		case 514:
			__asm__("mfdcr 3,514");
			break;
		case 515:
			__asm__("mfdcr 3,515");
			break;
		case 516:
			__asm__("mfdcr 3,516");
			break;
		case 517:
			__asm__("mfdcr 3,517");
			break;
		case 518:
			__asm__("mfdcr 3,518");
			break;
		case 519:
			__asm__("mfdcr 3,519");
			break;
		case 520:
			__asm__("mfdcr 3,520");
			break;
		case 521:
			__asm__("mfdcr 3,521");
			break;
		case 522:
			__asm__("mfdcr 3,522");
			break;
		case 523:
			__asm__("mfdcr 3,523");
			break;
		case 524:
			__asm__("mfdcr 3,524");
			break;
		case 525:
			__asm__("mfdcr 3,525");
			break;
		case 526:
			__asm__("mfdcr 3,526");
			break;
		case 527:
			__asm__("mfdcr 3,527");
			break;
		case 528:
			__asm__("mfdcr 3,528");
			break;
		case 529:
			__asm__("mfdcr 3,529");
			break;
		case 530:
			__asm__("mfdcr 3,530");
			break;
		case 531:
			__asm__("mfdcr 3,531");
			break;
		case 532:
			__asm__("mfdcr 3,532");
			break;
		case 533:
			__asm__("mfdcr 3,533");
			break;
		case 534:
			__asm__("mfdcr 3,534");
			break;
		case 535:
			__asm__("mfdcr 3,535");
			break;
		case 536:
			__asm__("mfdcr 3,536");
			break;
		case 537:
			__asm__("mfdcr 3,537");
			break;
		case 538:
			__asm__("mfdcr 3,538");
			break;
		case 539:
			__asm__("mfdcr 3,539");
			break;
		case 540:
			__asm__("mfdcr 3,540");
			break;
		case 541:
			__asm__("mfdcr 3,541");
			break;
		case 542:
			__asm__("mfdcr 3,542");
			break;
		case 543:
			__asm__("mfdcr 3,543");
			break;
		case 544:
			__asm__("mfdcr 3,544");
			break;
		case 545:
			__asm__("mfdcr 3,545");
			break;
		case 546:
			__asm__("mfdcr 3,546");
			break;
		case 547:
			__asm__("mfdcr 3,547");
			break;
		case 548:
			__asm__("mfdcr 3,548");
			break;
		case 549:
			__asm__("mfdcr 3,549");
			break;
		case 550:
			__asm__("mfdcr 3,550");
			break;
		case 551:
			__asm__("mfdcr 3,551");
			break;
		case 552:
			__asm__("mfdcr 3,552");
			break;
		case 553:
			__asm__("mfdcr 3,553");
			break;
		case 554:
			__asm__("mfdcr 3,554");
			break;
		case 555:
			__asm__("mfdcr 3,555");
			break;
		case 556:
			__asm__("mfdcr 3,556");
			break;
		case 557:
			__asm__("mfdcr 3,557");
			break;
		case 558:
			__asm__("mfdcr 3,558");
			break;
		case 559:
			__asm__("mfdcr 3,559");
			break;
		case 560:
			__asm__("mfdcr 3,560");
			break;
		case 561:
			__asm__("mfdcr 3,561");
			break;
		case 562:
			__asm__("mfdcr 3,562");
			break;
		case 563:
			__asm__("mfdcr 3,563");
			break;
		case 564:
			__asm__("mfdcr 3,564");
			break;
		case 565:
			__asm__("mfdcr 3,565");
			break;
		case 566:
			__asm__("mfdcr 3,566");
			break;
		case 567:
			__asm__("mfdcr 3,567");
			break;
		case 568:
			__asm__("mfdcr 3,568");
			break;
		case 569:
			__asm__("mfdcr 3,569");
			break;
		case 570:
			__asm__("mfdcr 3,570");
			break;
		case 571:
			__asm__("mfdcr 3,571");
			break;
		case 572:
			__asm__("mfdcr 3,572");
			break;
		case 573:
			__asm__("mfdcr 3,573");
			break;
		case 574:
			__asm__("mfdcr 3,574");
			break;
		case 575:
			__asm__("mfdcr 3,575");
			break;
		case 576:
			__asm__("mfdcr 3,576");
			break;
		case 577:
			__asm__("mfdcr 3,577");
			break;
		case 578:
			__asm__("mfdcr 3,578");
			break;
		case 579:
			__asm__("mfdcr 3,579");
			break;
		case 580:
			__asm__("mfdcr 3,580");
			break;
		case 581:
			__asm__("mfdcr 3,581");
			break;
		case 582:
			__asm__("mfdcr 3,582");
			break;
		case 583:
			__asm__("mfdcr 3,583");
			break;
		case 584:
			__asm__("mfdcr 3,584");
			break;
		case 585:
			__asm__("mfdcr 3,585");
			break;
		case 586:
			__asm__("mfdcr 3,586");
			break;
		case 587:
			__asm__("mfdcr 3,587");
			break;
		case 588:
			__asm__("mfdcr 3,588");
			break;
		case 589:
			__asm__("mfdcr 3,589");
			break;
		case 590:
			__asm__("mfdcr 3,590");
			break;
		case 591:
			__asm__("mfdcr 3,591");
			break;
		case 592:
			__asm__("mfdcr 3,592");
			break;
		case 593:
			__asm__("mfdcr 3,593");
			break;
		case 594:
			__asm__("mfdcr 3,594");
			break;
		case 595:
			__asm__("mfdcr 3,595");
			break;
		case 596:
			__asm__("mfdcr 3,596");
			break;
		case 597:
			__asm__("mfdcr 3,597");
			break;
		case 598:
			__asm__("mfdcr 3,598");
			break;
		case 599:
			__asm__("mfdcr 3,599");
			break;
		case 600:
			__asm__("mfdcr 3,600");
			break;
		case 601:
			__asm__("mfdcr 3,601");
			break;
		case 602:
			__asm__("mfdcr 3,602");
			break;
		case 603:
			__asm__("mfdcr 3,603");
			break;
		case 604:
			__asm__("mfdcr 3,604");
			break;
		case 605:
			__asm__("mfdcr 3,605");
			break;
		case 606:
			__asm__("mfdcr 3,606");
			break;
		case 607:
			__asm__("mfdcr 3,607");
			break;
		case 608:
			__asm__("mfdcr 3,608");
			break;
		case 609:
			__asm__("mfdcr 3,609");
			break;
		case 610:
			__asm__("mfdcr 3,610");
			break;
		case 611:
			__asm__("mfdcr 3,611");
			break;
		case 612:
			__asm__("mfdcr 3,612");
			break;
		case 613:
			__asm__("mfdcr 3,613");
			break;
		case 614:
			__asm__("mfdcr 3,614");
			break;
		case 615:
			__asm__("mfdcr 3,615");
			break;
		case 616:
			__asm__("mfdcr 3,616");
			break;
		case 617:
			__asm__("mfdcr 3,617");
			break;
		case 618:
			__asm__("mfdcr 3,618");
			break;
		case 619:
			__asm__("mfdcr 3,619");
			break;
		case 620:
			__asm__("mfdcr 3,620");
			break;
		case 621:
			__asm__("mfdcr 3,621");
			break;
		case 622:
			__asm__("mfdcr 3,622");
			break;
		case 623:
			__asm__("mfdcr 3,623");
			break;
		case 624:
			__asm__("mfdcr 3,624");
			break;
		case 625:
			__asm__("mfdcr 3,625");
			break;
		case 626:
			__asm__("mfdcr 3,626");
			break;
		case 627:
			__asm__("mfdcr 3,627");
			break;
		case 628:
			__asm__("mfdcr 3,628");
			break;
		case 629:
			__asm__("mfdcr 3,629");
			break;
		case 630:
			__asm__("mfdcr 3,630");
			break;
		case 631:
			__asm__("mfdcr 3,631");
			break;
		case 632:
			__asm__("mfdcr 3,632");
			break;
		case 633:
			__asm__("mfdcr 3,633");
			break;
		case 634:
			__asm__("mfdcr 3,634");
			break;
		case 635:
			__asm__("mfdcr 3,635");
			break;
		case 636:
			__asm__("mfdcr 3,636");
			break;
		case 637:
			__asm__("mfdcr 3,637");
			break;
		case 638:
			__asm__("mfdcr 3,638");
			break;
		case 639:
			__asm__("mfdcr 3,639");
			break;
		case 640:
			__asm__("mfdcr 3,640");
			break;
		case 641:
			__asm__("mfdcr 3,641");
			break;
		case 642:
			__asm__("mfdcr 3,642");
			break;
		case 643:
			__asm__("mfdcr 3,643");
			break;
		case 644:
			__asm__("mfdcr 3,644");
			break;
		case 645:
			__asm__("mfdcr 3,645");
			break;
		case 646:
			__asm__("mfdcr 3,646");
			break;
		case 647:
			__asm__("mfdcr 3,647");
			break;
		case 648:
			__asm__("mfdcr 3,648");
			break;
		case 649:
			__asm__("mfdcr 3,649");
			break;
		case 650:
			__asm__("mfdcr 3,650");
			break;
		case 651:
			__asm__("mfdcr 3,651");
			break;
		case 652:
			__asm__("mfdcr 3,652");
			break;
		case 653:
			__asm__("mfdcr 3,653");
			break;
		case 654:
			__asm__("mfdcr 3,654");
			break;
		case 655:
			__asm__("mfdcr 3,655");
			break;
		case 656:
			__asm__("mfdcr 3,656");
			break;
		case 657:
			__asm__("mfdcr 3,657");
			break;
		case 658:
			__asm__("mfdcr 3,658");
			break;
		case 659:
			__asm__("mfdcr 3,659");
			break;
		case 660:
			__asm__("mfdcr 3,660");
			break;
		case 661:
			__asm__("mfdcr 3,661");
			break;
		case 662:
			__asm__("mfdcr 3,662");
			break;
		case 663:
			__asm__("mfdcr 3,663");
			break;
		case 664:
			__asm__("mfdcr 3,664");
			break;
		case 665:
			__asm__("mfdcr 3,665");
			break;
		case 666:
			__asm__("mfdcr 3,666");
			break;
		case 667:
			__asm__("mfdcr 3,667");
			break;
		case 668:
			__asm__("mfdcr 3,668");
			break;
		case 669:
			__asm__("mfdcr 3,669");
			break;
		case 670:
			__asm__("mfdcr 3,670");
			break;
		case 671:
			__asm__("mfdcr 3,671");
			break;
		case 672:
			__asm__("mfdcr 3,672");
			break;
		case 673:
			__asm__("mfdcr 3,673");
			break;
		case 674:
			__asm__("mfdcr 3,674");
			break;
		case 675:
			__asm__("mfdcr 3,675");
			break;
		case 676:
			__asm__("mfdcr 3,676");
			break;
		case 677:
			__asm__("mfdcr 3,677");
			break;
		case 678:
			__asm__("mfdcr 3,678");
			break;
		case 679:
			__asm__("mfdcr 3,679");
			break;
		case 680:
			__asm__("mfdcr 3,680");
			break;
		case 681:
			__asm__("mfdcr 3,681");
			break;
		case 682:
			__asm__("mfdcr 3,682");
			break;
		case 683:
			__asm__("mfdcr 3,683");
			break;
		case 684:
			__asm__("mfdcr 3,684");
			break;
		case 685:
			__asm__("mfdcr 3,685");
			break;
		case 686:
			__asm__("mfdcr 3,686");
			break;
		case 687:
			__asm__("mfdcr 3,687");
			break;
		case 688:
			__asm__("mfdcr 3,688");
			break;
		case 689:
			__asm__("mfdcr 3,689");
			break;
		case 690:
			__asm__("mfdcr 3,690");
			break;
		case 691:
			__asm__("mfdcr 3,691");
			break;
		case 692:
			__asm__("mfdcr 3,692");
			break;
		case 693:
			__asm__("mfdcr 3,693");
			break;
		case 694:
			__asm__("mfdcr 3,694");
			break;
		case 695:
			__asm__("mfdcr 3,695");
			break;
		case 696:
			__asm__("mfdcr 3,696");
			break;
		case 697:
			__asm__("mfdcr 3,697");
			break;
		case 698:
			__asm__("mfdcr 3,698");
			break;
		case 699:
			__asm__("mfdcr 3,699");
			break;
		case 700:
			__asm__("mfdcr 3,700");
			break;
		case 701:
			__asm__("mfdcr 3,701");
			break;
		case 702:
			__asm__("mfdcr 3,702");
			break;
		case 703:
			__asm__("mfdcr 3,703");
			break;
		case 704:
			__asm__("mfdcr 3,704");
			break;
		case 705:
			__asm__("mfdcr 3,705");
			break;
		case 706:
			__asm__("mfdcr 3,706");
			break;
		case 707:
			__asm__("mfdcr 3,707");
			break;
		case 708:
			__asm__("mfdcr 3,708");
			break;
		case 709:
			__asm__("mfdcr 3,709");
			break;
		case 710:
			__asm__("mfdcr 3,710");
			break;
		case 711:
			__asm__("mfdcr 3,711");
			break;
		case 712:
			__asm__("mfdcr 3,712");
			break;
		case 713:
			__asm__("mfdcr 3,713");
			break;
		case 714:
			__asm__("mfdcr 3,714");
			break;
		case 715:
			__asm__("mfdcr 3,715");
			break;
		case 716:
			__asm__("mfdcr 3,716");
			break;
		case 717:
			__asm__("mfdcr 3,717");
			break;
		case 718:
			__asm__("mfdcr 3,718");
			break;
		case 719:
			__asm__("mfdcr 3,719");
			break;
		case 720:
			__asm__("mfdcr 3,720");
			break;
		case 721:
			__asm__("mfdcr 3,721");
			break;
		case 722:
			__asm__("mfdcr 3,722");
			break;
		case 723:
			__asm__("mfdcr 3,723");
			break;
		case 724:
			__asm__("mfdcr 3,724");
			break;
		case 725:
			__asm__("mfdcr 3,725");
			break;
		case 726:
			__asm__("mfdcr 3,726");
			break;
		case 727:
			__asm__("mfdcr 3,727");
			break;
		case 728:
			__asm__("mfdcr 3,728");
			break;
		case 729:
			__asm__("mfdcr 3,729");
			break;
		case 730:
			__asm__("mfdcr 3,730");
			break;
		case 731:
			__asm__("mfdcr 3,731");
			break;
		case 732:
			__asm__("mfdcr 3,732");
			break;
		case 733:
			__asm__("mfdcr 3,733");
			break;
		case 734:
			__asm__("mfdcr 3,734");
			break;
		case 735:
			__asm__("mfdcr 3,735");
			break;
		case 736:
			__asm__("mfdcr 3,736");
			break;
		case 737:
			__asm__("mfdcr 3,737");
			break;
		case 738:
			__asm__("mfdcr 3,738");
			break;
		case 739:
			__asm__("mfdcr 3,739");
			break;
		case 740:
			__asm__("mfdcr 3,740");
			break;
		case 741:
			__asm__("mfdcr 3,741");
			break;
		case 742:
			__asm__("mfdcr 3,742");
			break;
		case 743:
			__asm__("mfdcr 3,743");
			break;
		case 744:
			__asm__("mfdcr 3,744");
			break;
		case 745:
			__asm__("mfdcr 3,745");
			break;
		case 746:
			__asm__("mfdcr 3,746");
			break;
		case 747:
			__asm__("mfdcr 3,747");
			break;
		case 748:
			__asm__("mfdcr 3,748");
			break;
		case 749:
			__asm__("mfdcr 3,749");
			break;
		case 750:
			__asm__("mfdcr 3,750");
			break;
		case 751:
			__asm__("mfdcr 3,751");
			break;
		case 752:
			__asm__("mfdcr 3,752");
			break;
		case 753:
			__asm__("mfdcr 3,753");
			break;
		case 754:
			__asm__("mfdcr 3,754");
			break;
		case 755:
			__asm__("mfdcr 3,755");
			break;
		case 756:
			__asm__("mfdcr 3,756");
			break;
		case 757:
			__asm__("mfdcr 3,757");
			break;
		case 758:
			__asm__("mfdcr 3,758");
			break;
		case 759:
			__asm__("mfdcr 3,759");
			break;
		case 760:
			__asm__("mfdcr 3,760");
			break;
		case 761:
			__asm__("mfdcr 3,761");
			break;
		case 762:
			__asm__("mfdcr 3,762");
			break;
		case 763:
			__asm__("mfdcr 3,763");
			break;
		case 764:
			__asm__("mfdcr 3,764");
			break;
		case 765:
			__asm__("mfdcr 3,765");
			break;
		case 766:
			__asm__("mfdcr 3,766");
			break;
		case 767:
			__asm__("mfdcr 3,767");
			break;
		case 768:
			__asm__("mfdcr 3,768");
			break;
		case 769:
			__asm__("mfdcr 3,769");
			break;
		case 770:
			__asm__("mfdcr 3,770");
			break;
		case 771:
			__asm__("mfdcr 3,771");
			break;
		case 772:
			__asm__("mfdcr 3,772");
			break;
		case 773:
			__asm__("mfdcr 3,773");
			break;
		case 774:
			__asm__("mfdcr 3,774");
			break;
		case 775:
			__asm__("mfdcr 3,775");
			break;
		case 776:
			__asm__("mfdcr 3,776");
			break;
		case 777:
			__asm__("mfdcr 3,777");
			break;
		case 778:
			__asm__("mfdcr 3,778");
			break;
		case 779:
			__asm__("mfdcr 3,779");
			break;
		case 780:
			__asm__("mfdcr 3,780");
			break;
		case 781:
			__asm__("mfdcr 3,781");
			break;
		case 782:
			__asm__("mfdcr 3,782");
			break;
		case 783:
			__asm__("mfdcr 3,783");
			break;
		case 784:
			__asm__("mfdcr 3,784");
			break;
		case 785:
			__asm__("mfdcr 3,785");
			break;
		case 786:
			__asm__("mfdcr 3,786");
			break;
		case 787:
			__asm__("mfdcr 3,787");
			break;
		case 788:
			__asm__("mfdcr 3,788");
			break;
		case 789:
			__asm__("mfdcr 3,789");
			break;
		case 790:
			__asm__("mfdcr 3,790");
			break;
		case 791:
			__asm__("mfdcr 3,791");
			break;
		case 792:
			__asm__("mfdcr 3,792");
			break;
		case 793:
			__asm__("mfdcr 3,793");
			break;
		case 794:
			__asm__("mfdcr 3,794");
			break;
		case 795:
			__asm__("mfdcr 3,795");
			break;
		case 796:
			__asm__("mfdcr 3,796");
			break;
		case 797:
			__asm__("mfdcr 3,797");
			break;
		case 798:
			__asm__("mfdcr 3,798");
			break;
		case 799:
			__asm__("mfdcr 3,799");
			break;
		case 800:
			__asm__("mfdcr 3,800");
			break;
		case 801:
			__asm__("mfdcr 3,801");
			break;
		case 802:
			__asm__("mfdcr 3,802");
			break;
		case 803:
			__asm__("mfdcr 3,803");
			break;
		case 804:
			__asm__("mfdcr 3,804");
			break;
		case 805:
			__asm__("mfdcr 3,805");
			break;
		case 806:
			__asm__("mfdcr 3,806");
			break;
		case 807:
			__asm__("mfdcr 3,807");
			break;
		case 808:
			__asm__("mfdcr 3,808");
			break;
		case 809:
			__asm__("mfdcr 3,809");
			break;
		case 810:
			__asm__("mfdcr 3,810");
			break;
		case 811:
			__asm__("mfdcr 3,811");
			break;
		case 812:
			__asm__("mfdcr 3,812");
			break;
		case 813:
			__asm__("mfdcr 3,813");
			break;
		case 814:
			__asm__("mfdcr 3,814");
			break;
		case 815:
			__asm__("mfdcr 3,815");
			break;
		case 816:
			__asm__("mfdcr 3,816");
			break;
		case 817:
			__asm__("mfdcr 3,817");
			break;
		case 818:
			__asm__("mfdcr 3,818");
			break;
		case 819:
			__asm__("mfdcr 3,819");
			break;
		case 820:
			__asm__("mfdcr 3,820");
			break;
		case 821:
			__asm__("mfdcr 3,821");
			break;
		case 822:
			__asm__("mfdcr 3,822");
			break;
		case 823:
			__asm__("mfdcr 3,823");
			break;
		case 824:
			__asm__("mfdcr 3,824");
			break;
		case 825:
			__asm__("mfdcr 3,825");
			break;
		case 826:
			__asm__("mfdcr 3,826");
			break;
		case 827:
			__asm__("mfdcr 3,827");
			break;
		case 828:
			__asm__("mfdcr 3,828");
			break;
		case 829:
			__asm__("mfdcr 3,829");
			break;
		case 830:
			__asm__("mfdcr 3,830");
			break;
		case 831:
			__asm__("mfdcr 3,831");
			break;
		case 832:
			__asm__("mfdcr 3,832");
			break;
		case 833:
			__asm__("mfdcr 3,833");
			break;
		case 834:
			__asm__("mfdcr 3,834");
			break;
		case 835:
			__asm__("mfdcr 3,835");
			break;
		case 836:
			__asm__("mfdcr 3,836");
			break;
		case 837:
			__asm__("mfdcr 3,837");
			break;
		case 838:
			__asm__("mfdcr 3,838");
			break;
		case 839:
			__asm__("mfdcr 3,839");
			break;
		case 840:
			__asm__("mfdcr 3,840");
			break;
		case 841:
			__asm__("mfdcr 3,841");
			break;
		case 842:
			__asm__("mfdcr 3,842");
			break;
		case 843:
			__asm__("mfdcr 3,843");
			break;
		case 844:
			__asm__("mfdcr 3,844");
			break;
		case 845:
			__asm__("mfdcr 3,845");
			break;
		case 846:
			__asm__("mfdcr 3,846");
			break;
		case 847:
			__asm__("mfdcr 3,847");
			break;
		case 848:
			__asm__("mfdcr 3,848");
			break;
		case 849:
			__asm__("mfdcr 3,849");
			break;
		case 850:
			__asm__("mfdcr 3,850");
			break;
		case 851:
			__asm__("mfdcr 3,851");
			break;
		case 852:
			__asm__("mfdcr 3,852");
			break;
		case 853:
			__asm__("mfdcr 3,853");
			break;
		case 854:
			__asm__("mfdcr 3,854");
			break;
		case 855:
			__asm__("mfdcr 3,855");
			break;
		case 856:
			__asm__("mfdcr 3,856");
			break;
		case 857:
			__asm__("mfdcr 3,857");
			break;
		case 858:
			__asm__("mfdcr 3,858");
			break;
		case 859:
			__asm__("mfdcr 3,859");
			break;
		case 860:
			__asm__("mfdcr 3,860");
			break;
		case 861:
			__asm__("mfdcr 3,861");
			break;
		case 862:
			__asm__("mfdcr 3,862");
			break;
		case 863:
			__asm__("mfdcr 3,863");
			break;
		case 864:
			__asm__("mfdcr 3,864");
			break;
		case 865:
			__asm__("mfdcr 3,865");
			break;
		case 866:
			__asm__("mfdcr 3,866");
			break;
		case 867:
			__asm__("mfdcr 3,867");
			break;
		case 868:
			__asm__("mfdcr 3,868");
			break;
		case 869:
			__asm__("mfdcr 3,869");
			break;
		case 870:
			__asm__("mfdcr 3,870");
			break;
		case 871:
			__asm__("mfdcr 3,871");
			break;
		case 872:
			__asm__("mfdcr 3,872");
			break;
		case 873:
			__asm__("mfdcr 3,873");
			break;
		case 874:
			__asm__("mfdcr 3,874");
			break;
		case 875:
			__asm__("mfdcr 3,875");
			break;
		case 876:
			__asm__("mfdcr 3,876");
			break;
		case 877:
			__asm__("mfdcr 3,877");
			break;
		case 878:
			__asm__("mfdcr 3,878");
			break;
		case 879:
			__asm__("mfdcr 3,879");
			break;
		case 880:
			__asm__("mfdcr 3,880");
			break;
		case 881:
			__asm__("mfdcr 3,881");
			break;
		case 882:
			__asm__("mfdcr 3,882");
			break;
		case 883:
			__asm__("mfdcr 3,883");
			break;
		case 884:
			__asm__("mfdcr 3,884");
			break;
		case 885:
			__asm__("mfdcr 3,885");
			break;
		case 886:
			__asm__("mfdcr 3,886");
			break;
		case 887:
			__asm__("mfdcr 3,887");
			break;
		case 888:
			__asm__("mfdcr 3,888");
			break;
		case 889:
			__asm__("mfdcr 3,889");
			break;
		case 890:
			__asm__("mfdcr 3,890");
			break;
		case 891:
			__asm__("mfdcr 3,891");
			break;
		case 892:
			__asm__("mfdcr 3,892");
			break;
		case 893:
			__asm__("mfdcr 3,893");
			break;
		case 894:
			__asm__("mfdcr 3,894");
			break;
		case 895:
			__asm__("mfdcr 3,895");
			break;
		case 896:
			__asm__("mfdcr 3,896");
			break;
		case 897:
			__asm__("mfdcr 3,897");
			break;
		case 898:
			__asm__("mfdcr 3,898");
			break;
		case 899:
			__asm__("mfdcr 3,899");
			break;
		case 900:
			__asm__("mfdcr 3,900");
			break;
		case 901:
			__asm__("mfdcr 3,901");
			break;
		case 902:
			__asm__("mfdcr 3,902");
			break;
		case 903:
			__asm__("mfdcr 3,903");
			break;
		case 904:
			__asm__("mfdcr 3,904");
			break;
		case 905:
			__asm__("mfdcr 3,905");
			break;
		case 906:
			__asm__("mfdcr 3,906");
			break;
		case 907:
			__asm__("mfdcr 3,907");
			break;
		case 908:
			__asm__("mfdcr 3,908");
			break;
		case 909:
			__asm__("mfdcr 3,909");
			break;
		case 910:
			__asm__("mfdcr 3,910");
			break;
		case 911:
			__asm__("mfdcr 3,911");
			break;
		case 912:
			__asm__("mfdcr 3,912");
			break;
		case 913:
			__asm__("mfdcr 3,913");
			break;
		case 914:
			__asm__("mfdcr 3,914");
			break;
		case 915:
			__asm__("mfdcr 3,915");
			break;
		case 916:
			__asm__("mfdcr 3,916");
			break;
		case 917:
			__asm__("mfdcr 3,917");
			break;
		case 918:
			__asm__("mfdcr 3,918");
			break;
		case 919:
			__asm__("mfdcr 3,919");
			break;
		case 920:
			__asm__("mfdcr 3,920");
			break;
		case 921:
			__asm__("mfdcr 3,921");
			break;
		case 922:
			__asm__("mfdcr 3,922");
			break;
		case 923:
			__asm__("mfdcr 3,923");
			break;
		case 924:
			__asm__("mfdcr 3,924");
			break;
		case 925:
			__asm__("mfdcr 3,925");
			break;
		case 926:
			__asm__("mfdcr 3,926");
			break;
		case 927:
			__asm__("mfdcr 3,927");
			break;
		case 928:
			__asm__("mfdcr 3,928");
			break;
		case 929:
			__asm__("mfdcr 3,929");
			break;
		case 930:
			__asm__("mfdcr 3,930");
			break;
		case 931:
			__asm__("mfdcr 3,931");
			break;
		case 932:
			__asm__("mfdcr 3,932");
			break;
		case 933:
			__asm__("mfdcr 3,933");
			break;
		case 934:
			__asm__("mfdcr 3,934");
			break;
		case 935:
			__asm__("mfdcr 3,935");
			break;
		case 936:
			__asm__("mfdcr 3,936");
			break;
		case 937:
			__asm__("mfdcr 3,937");
			break;
		case 938:
			__asm__("mfdcr 3,938");
			break;
		case 939:
			__asm__("mfdcr 3,939");
			break;
		case 940:
			__asm__("mfdcr 3,940");
			break;
		case 941:
			__asm__("mfdcr 3,941");
			break;
		case 942:
			__asm__("mfdcr 3,942");
			break;
		case 943:
			__asm__("mfdcr 3,943");
			break;
		case 944:
			__asm__("mfdcr 3,944");
			break;
		case 945:
			__asm__("mfdcr 3,945");
			break;
		case 946:
			__asm__("mfdcr 3,946");
			break;
		case 947:
			__asm__("mfdcr 3,947");
			break;
		case 948:
			__asm__("mfdcr 3,948");
			break;
		case 949:
			__asm__("mfdcr 3,949");
			break;
		case 950:
			__asm__("mfdcr 3,950");
			break;
		case 951:
			__asm__("mfdcr 3,951");
			break;
		case 952:
			__asm__("mfdcr 3,952");
			break;
		case 953:
			__asm__("mfdcr 3,953");
			break;
		case 954:
			__asm__("mfdcr 3,954");
			break;
		case 955:
			__asm__("mfdcr 3,955");
			break;
		case 956:
			__asm__("mfdcr 3,956");
			break;
		case 957:
			__asm__("mfdcr 3,957");
			break;
		case 958:
			__asm__("mfdcr 3,958");
			break;
		case 959:
			__asm__("mfdcr 3,959");
			break;
		case 960:
			__asm__("mfdcr 3,960");
			break;
		case 961:
			__asm__("mfdcr 3,961");
			break;
		case 962:
			__asm__("mfdcr 3,962");
			break;
		case 963:
			__asm__("mfdcr 3,963");
			break;
		case 964:
			__asm__("mfdcr 3,964");
			break;
		case 965:
			__asm__("mfdcr 3,965");
			break;
		case 966:
			__asm__("mfdcr 3,966");
			break;
		case 967:
			__asm__("mfdcr 3,967");
			break;
		case 968:
			__asm__("mfdcr 3,968");
			break;
		case 969:
			__asm__("mfdcr 3,969");
			break;
		case 970:
			__asm__("mfdcr 3,970");
			break;
		case 971:
			__asm__("mfdcr 3,971");
			break;
		case 972:
			__asm__("mfdcr 3,972");
			break;
		case 973:
			__asm__("mfdcr 3,973");
			break;
		case 974:
			__asm__("mfdcr 3,974");
			break;
		case 975:
			__asm__("mfdcr 3,975");
			break;
		case 976:
			__asm__("mfdcr 3,976");
			break;
		case 977:
			__asm__("mfdcr 3,977");
			break;
		case 978:
			__asm__("mfdcr 3,978");
			break;
		case 979:
			__asm__("mfdcr 3,979");
			break;
		case 980:
			__asm__("mfdcr 3,980");
			break;
		case 981:
			__asm__("mfdcr 3,981");
			break;
		case 982:
			__asm__("mfdcr 3,982");
			break;
		case 983:
			__asm__("mfdcr 3,983");
			break;
		case 984:
			__asm__("mfdcr 3,984");
			break;
		case 985:
			__asm__("mfdcr 3,985");
			break;
		case 986:
			__asm__("mfdcr 3,986");
			break;
		case 987:
			__asm__("mfdcr 3,987");
			break;
		case 988:
			__asm__("mfdcr 3,988");
			break;
		case 989:
			__asm__("mfdcr 3,989");
			break;
		case 990:
			__asm__("mfdcr 3,990");
			break;
		case 991:
			__asm__("mfdcr 3,991");
			break;
		case 992:
			__asm__("mfdcr 3,992");
			break;
		case 993:
			__asm__("mfdcr 3,993");
			break;
		case 994:
			__asm__("mfdcr 3,994");
			break;
		case 995:
			__asm__("mfdcr 3,995");
			break;
		case 996:
			__asm__("mfdcr 3,996");
			break;
		case 997:
			__asm__("mfdcr 3,997");
			break;
		case 998:
			__asm__("mfdcr 3,998");
			break;
		case 999:
			__asm__("mfdcr 3,999");
			break;
		case 1000:
			__asm__("mfdcr 3,1000");
			break;
		case 1001:
			__asm__("mfdcr 3,1001");
			break;
		case 1002:
			__asm__("mfdcr 3,1002");
			break;
		case 1003:
			__asm__("mfdcr 3,1003");
			break;
		case 1004:
			__asm__("mfdcr 3,1004");
			break;
		case 1005:
			__asm__("mfdcr 3,1005");
			break;
		case 1006:
			__asm__("mfdcr 3,1006");
			break;
		case 1007:
			__asm__("mfdcr 3,1007");
			break;
		case 1008:
			__asm__("mfdcr 3,1008");
			break;
		case 1009:
			__asm__("mfdcr 3,1009");
			break;
		case 1010:
			__asm__("mfdcr 3,1010");
			break;
		case 1011:
			__asm__("mfdcr 3,1011");
			break;
		case 1012:
			__asm__("mfdcr 3,1012");
			break;
		case 1013:
			__asm__("mfdcr 3,1013");
			break;
		case 1014:
			__asm__("mfdcr 3,1014");
			break;
		case 1015:
			__asm__("mfdcr 3,1015");
			break;
		case 1016:
			__asm__("mfdcr 3,1016");
			break;
		case 1017:
			__asm__("mfdcr 3,1017");
			break;
		case 1018:
			__asm__("mfdcr 3,1018");
			break;
		case 1019:
			__asm__("mfdcr 3,1019");
			break;
		case 1020:
			__asm__("mfdcr 3,1020");
			break;
		case 1021:
			__asm__("mfdcr 3,1021");
			break;
		case 1022:
			__asm__("mfdcr 3,1022");
			break;
		case 1023:
			__asm__("mfdcr 3,1023");
			break;
	}
}

void dcr_write(int dcrn, unsigned long value)
{
	switch(dcrn){
		case 0:
			__asm__("mtdcr 0,4");
			break;
		case 1:
			__asm__("mtdcr 1,4");
			break;
		case 2:
			__asm__("mtdcr 2,4");
			break;
		case 3:
			__asm__("mtdcr 3,4");
			break;
		case 4:
			__asm__("mtdcr 4,4");
			break;
		case 5:
			__asm__("mtdcr 5,4");
			break;
		case 6:
			__asm__("mtdcr 6,4");
			break;
		case 7:
			__asm__("mtdcr 7,4");
			break;
		case 8:
			__asm__("mtdcr 8,4");
			break;
		case 9:
			__asm__("mtdcr 9,4");
			break;
		case 10:
			__asm__("mtdcr 10,4");
			break;
		case 11:
			__asm__("mtdcr 11,4");
			break;
		case 12:
			__asm__("mtdcr 12,4");
			break;
		case 13:
			__asm__("mtdcr 13,4");
			break;
		case 14:
			__asm__("mtdcr 14,4");
			break;
		case 15:
			__asm__("mtdcr 15,4");
			break;
		case 16:
			__asm__("mtdcr 16,4");
			break;
		case 17:
			__asm__("mtdcr 17,4");
			break;
		case 18:
			__asm__("mtdcr 18,4");
			break;
		case 19:
			__asm__("mtdcr 19,4");
			break;
		case 20:
			__asm__("mtdcr 20,4");
			break;
		case 21:
			__asm__("mtdcr 21,4");
			break;
		case 22:
			__asm__("mtdcr 22,4");
			break;
		case 23:
			__asm__("mtdcr 23,4");
			break;
		case 24:
			__asm__("mtdcr 24,4");
			break;
		case 25:
			__asm__("mtdcr 25,4");
			break;
		case 26:
			__asm__("mtdcr 26,4");
			break;
		case 27:
			__asm__("mtdcr 27,4");
			break;
		case 28:
			__asm__("mtdcr 28,4");
			break;
		case 29:
			__asm__("mtdcr 29,4");
			break;
		case 30:
			__asm__("mtdcr 30,4");
			break;
		case 31:
			__asm__("mtdcr 31,4");
			break;
		case 32:
			__asm__("mtdcr 32,4");
			break;
		case 33:
			__asm__("mtdcr 33,4");
			break;
		case 34:
			__asm__("mtdcr 34,4");
			break;
		case 35:
			__asm__("mtdcr 35,4");
			break;
		case 36:
			__asm__("mtdcr 36,4");
			break;
		case 37:
			__asm__("mtdcr 37,4");
			break;
		case 38:
			__asm__("mtdcr 38,4");
			break;
		case 39:
			__asm__("mtdcr 39,4");
			break;
		case 40:
			__asm__("mtdcr 40,4");
			break;
		case 41:
			__asm__("mtdcr 41,4");
			break;
		case 42:
			__asm__("mtdcr 42,4");
			break;
		case 43:
			__asm__("mtdcr 43,4");
			break;
		case 44:
			__asm__("mtdcr 44,4");
			break;
		case 45:
			__asm__("mtdcr 45,4");
			break;
		case 46:
			__asm__("mtdcr 46,4");
			break;
		case 47:
			__asm__("mtdcr 47,4");
			break;
		case 48:
			__asm__("mtdcr 48,4");
			break;
		case 49:
			__asm__("mtdcr 49,4");
			break;
		case 50:
			__asm__("mtdcr 50,4");
			break;
		case 51:
			__asm__("mtdcr 51,4");
			break;
		case 52:
			__asm__("mtdcr 52,4");
			break;
		case 53:
			__asm__("mtdcr 53,4");
			break;
		case 54:
			__asm__("mtdcr 54,4");
			break;
		case 55:
			__asm__("mtdcr 55,4");
			break;
		case 56:
			__asm__("mtdcr 56,4");
			break;
		case 57:
			__asm__("mtdcr 57,4");
			break;
		case 58:
			__asm__("mtdcr 58,4");
			break;
		case 59:
			__asm__("mtdcr 59,4");
			break;
		case 60:
			__asm__("mtdcr 60,4");
			break;
		case 61:
			__asm__("mtdcr 61,4");
			break;
		case 62:
			__asm__("mtdcr 62,4");
			break;
		case 63:
			__asm__("mtdcr 63,4");
			break;
		case 64:
			__asm__("mtdcr 64,4");
			break;
		case 65:
			__asm__("mtdcr 65,4");
			break;
		case 66:
			__asm__("mtdcr 66,4");
			break;
		case 67:
			__asm__("mtdcr 67,4");
			break;
		case 68:
			__asm__("mtdcr 68,4");
			break;
		case 69:
			__asm__("mtdcr 69,4");
			break;
		case 70:
			__asm__("mtdcr 70,4");
			break;
		case 71:
			__asm__("mtdcr 71,4");
			break;
		case 72:
			__asm__("mtdcr 72,4");
			break;
		case 73:
			__asm__("mtdcr 73,4");
			break;
		case 74:
			__asm__("mtdcr 74,4");
			break;
		case 75:
			__asm__("mtdcr 75,4");
			break;
		case 76:
			__asm__("mtdcr 76,4");
			break;
		case 77:
			__asm__("mtdcr 77,4");
			break;
		case 78:
			__asm__("mtdcr 78,4");
			break;
		case 79:
			__asm__("mtdcr 79,4");
			break;
		case 80:
			__asm__("mtdcr 80,4");
			break;
		case 81:
			__asm__("mtdcr 81,4");
			break;
		case 82:
			__asm__("mtdcr 82,4");
			break;
		case 83:
			__asm__("mtdcr 83,4");
			break;
		case 84:
			__asm__("mtdcr 84,4");
			break;
		case 85:
			__asm__("mtdcr 85,4");
			break;
		case 86:
			__asm__("mtdcr 86,4");
			break;
		case 87:
			__asm__("mtdcr 87,4");
			break;
		case 88:
			__asm__("mtdcr 88,4");
			break;
		case 89:
			__asm__("mtdcr 89,4");
			break;
		case 90:
			__asm__("mtdcr 90,4");
			break;
		case 91:
			__asm__("mtdcr 91,4");
			break;
		case 92:
			__asm__("mtdcr 92,4");
			break;
		case 93:
			__asm__("mtdcr 93,4");
			break;
		case 94:
			__asm__("mtdcr 94,4");
			break;
		case 95:
			__asm__("mtdcr 95,4");
			break;
		case 96:
			__asm__("mtdcr 96,4");
			break;
		case 97:
			__asm__("mtdcr 97,4");
			break;
		case 98:
			__asm__("mtdcr 98,4");
			break;
		case 99:
			__asm__("mtdcr 99,4");
			break;
		case 100:
			__asm__("mtdcr 100,4");
			break;
		case 101:
			__asm__("mtdcr 101,4");
			break;
		case 102:
			__asm__("mtdcr 102,4");
			break;
		case 103:
			__asm__("mtdcr 103,4");
			break;
		case 104:
			__asm__("mtdcr 104,4");
			break;
		case 105:
			__asm__("mtdcr 105,4");
			break;
		case 106:
			__asm__("mtdcr 106,4");
			break;
		case 107:
			__asm__("mtdcr 107,4");
			break;
		case 108:
			__asm__("mtdcr 108,4");
			break;
		case 109:
			__asm__("mtdcr 109,4");
			break;
		case 110:
			__asm__("mtdcr 110,4");
			break;
		case 111:
			__asm__("mtdcr 111,4");
			break;
		case 112:
			__asm__("mtdcr 112,4");
			break;
		case 113:
			__asm__("mtdcr 113,4");
			break;
		case 114:
			__asm__("mtdcr 114,4");
			break;
		case 115:
			__asm__("mtdcr 115,4");
			break;
		case 116:
			__asm__("mtdcr 116,4");
			break;
		case 117:
			__asm__("mtdcr 117,4");
			break;
		case 118:
			__asm__("mtdcr 118,4");
			break;
		case 119:
			__asm__("mtdcr 119,4");
			break;
		case 120:
			__asm__("mtdcr 120,4");
			break;
		case 121:
			__asm__("mtdcr 121,4");
			break;
		case 122:
			__asm__("mtdcr 122,4");
			break;
		case 123:
			__asm__("mtdcr 123,4");
			break;
		case 124:
			__asm__("mtdcr 124,4");
			break;
		case 125:
			__asm__("mtdcr 125,4");
			break;
		case 126:
			__asm__("mtdcr 126,4");
			break;
		case 127:
			__asm__("mtdcr 127,4");
			break;
		case 128:
			__asm__("mtdcr 128,4");
			break;
		case 129:
			__asm__("mtdcr 129,4");
			break;
		case 130:
			__asm__("mtdcr 130,4");
			break;
		case 131:
			__asm__("mtdcr 131,4");
			break;
		case 132:
			__asm__("mtdcr 132,4");
			break;
		case 133:
			__asm__("mtdcr 133,4");
			break;
		case 134:
			__asm__("mtdcr 134,4");
			break;
		case 135:
			__asm__("mtdcr 135,4");
			break;
		case 136:
			__asm__("mtdcr 136,4");
			break;
		case 137:
			__asm__("mtdcr 137,4");
			break;
		case 138:
			__asm__("mtdcr 138,4");
			break;
		case 139:
			__asm__("mtdcr 139,4");
			break;
		case 140:
			__asm__("mtdcr 140,4");
			break;
		case 141:
			__asm__("mtdcr 141,4");
			break;
		case 142:
			__asm__("mtdcr 142,4");
			break;
		case 143:
			__asm__("mtdcr 143,4");
			break;
		case 144:
			__asm__("mtdcr 144,4");
			break;
		case 145:
			__asm__("mtdcr 145,4");
			break;
		case 146:
			__asm__("mtdcr 146,4");
			break;
		case 147:
			__asm__("mtdcr 147,4");
			break;
		case 148:
			__asm__("mtdcr 148,4");
			break;
		case 149:
			__asm__("mtdcr 149,4");
			break;
		case 150:
			__asm__("mtdcr 150,4");
			break;
		case 151:
			__asm__("mtdcr 151,4");
			break;
		case 152:
			__asm__("mtdcr 152,4");
			break;
		case 153:
			__asm__("mtdcr 153,4");
			break;
		case 154:
			__asm__("mtdcr 154,4");
			break;
		case 155:
			__asm__("mtdcr 155,4");
			break;
		case 156:
			__asm__("mtdcr 156,4");
			break;
		case 157:
			__asm__("mtdcr 157,4");
			break;
		case 158:
			__asm__("mtdcr 158,4");
			break;
		case 159:
			__asm__("mtdcr 159,4");
			break;
		case 160:
			__asm__("mtdcr 160,4");
			break;
		case 161:
			__asm__("mtdcr 161,4");
			break;
		case 162:
			__asm__("mtdcr 162,4");
			break;
		case 163:
			__asm__("mtdcr 163,4");
			break;
		case 164:
			__asm__("mtdcr 164,4");
			break;
		case 165:
			__asm__("mtdcr 165,4");
			break;
		case 166:
			__asm__("mtdcr 166,4");
			break;
		case 167:
			__asm__("mtdcr 167,4");
			break;
		case 168:
			__asm__("mtdcr 168,4");
			break;
		case 169:
			__asm__("mtdcr 169,4");
			break;
		case 170:
			__asm__("mtdcr 170,4");
			break;
		case 171:
			__asm__("mtdcr 171,4");
			break;
		case 172:
			__asm__("mtdcr 172,4");
			break;
		case 173:
			__asm__("mtdcr 173,4");
			break;
		case 174:
			__asm__("mtdcr 174,4");
			break;
		case 175:
			__asm__("mtdcr 175,4");
			break;
		case 176:
			__asm__("mtdcr 176,4");
			break;
		case 177:
			__asm__("mtdcr 177,4");
			break;
		case 178:
			__asm__("mtdcr 178,4");
			break;
		case 179:
			__asm__("mtdcr 179,4");
			break;
		case 180:
			__asm__("mtdcr 180,4");
			break;
		case 181:
			__asm__("mtdcr 181,4");
			break;
		case 182:
			__asm__("mtdcr 182,4");
			break;
		case 183:
			__asm__("mtdcr 183,4");
			break;
		case 184:
			__asm__("mtdcr 184,4");
			break;
		case 185:
			__asm__("mtdcr 185,4");
			break;
		case 186:
			__asm__("mtdcr 186,4");
			break;
		case 187:
			__asm__("mtdcr 187,4");
			break;
		case 188:
			__asm__("mtdcr 188,4");
			break;
		case 189:
			__asm__("mtdcr 189,4");
			break;
		case 190:
			__asm__("mtdcr 190,4");
			break;
		case 191:
			__asm__("mtdcr 191,4");
			break;
		case 192:
			__asm__("mtdcr 192,4");
			break;
		case 193:
			__asm__("mtdcr 193,4");
			break;
		case 194:
			__asm__("mtdcr 194,4");
			break;
		case 195:
			__asm__("mtdcr 195,4");
			break;
		case 196:
			__asm__("mtdcr 196,4");
			break;
		case 197:
			__asm__("mtdcr 197,4");
			break;
		case 198:
			__asm__("mtdcr 198,4");
			break;
		case 199:
			__asm__("mtdcr 199,4");
			break;
		case 200:
			__asm__("mtdcr 200,4");
			break;
		case 201:
			__asm__("mtdcr 201,4");
			break;
		case 202:
			__asm__("mtdcr 202,4");
			break;
		case 203:
			__asm__("mtdcr 203,4");
			break;
		case 204:
			__asm__("mtdcr 204,4");
			break;
		case 205:
			__asm__("mtdcr 205,4");
			break;
		case 206:
			__asm__("mtdcr 206,4");
			break;
		case 207:
			__asm__("mtdcr 207,4");
			break;
		case 208:
			__asm__("mtdcr 208,4");
			break;
		case 209:
			__asm__("mtdcr 209,4");
			break;
		case 210:
			__asm__("mtdcr 210,4");
			break;
		case 211:
			__asm__("mtdcr 211,4");
			break;
		case 212:
			__asm__("mtdcr 212,4");
			break;
		case 213:
			__asm__("mtdcr 213,4");
			break;
		case 214:
			__asm__("mtdcr 214,4");
			break;
		case 215:
			__asm__("mtdcr 215,4");
			break;
		case 216:
			__asm__("mtdcr 216,4");
			break;
		case 217:
			__asm__("mtdcr 217,4");
			break;
		case 218:
			__asm__("mtdcr 218,4");
			break;
		case 219:
			__asm__("mtdcr 219,4");
			break;
		case 220:
			__asm__("mtdcr 220,4");
			break;
		case 221:
			__asm__("mtdcr 221,4");
			break;
		case 222:
			__asm__("mtdcr 222,4");
			break;
		case 223:
			__asm__("mtdcr 223,4");
			break;
		case 224:
			__asm__("mtdcr 224,4");
			break;
		case 225:
			__asm__("mtdcr 225,4");
			break;
		case 226:
			__asm__("mtdcr 226,4");
			break;
		case 227:
			__asm__("mtdcr 227,4");
			break;
		case 228:
			__asm__("mtdcr 228,4");
			break;
		case 229:
			__asm__("mtdcr 229,4");
			break;
		case 230:
			__asm__("mtdcr 230,4");
			break;
		case 231:
			__asm__("mtdcr 231,4");
			break;
		case 232:
			__asm__("mtdcr 232,4");
			break;
		case 233:
			__asm__("mtdcr 233,4");
			break;
		case 234:
			__asm__("mtdcr 234,4");
			break;
		case 235:
			__asm__("mtdcr 235,4");
			break;
		case 236:
			__asm__("mtdcr 236,4");
			break;
		case 237:
			__asm__("mtdcr 237,4");
			break;
		case 238:
			__asm__("mtdcr 238,4");
			break;
		case 239:
			__asm__("mtdcr 239,4");
			break;
		case 240:
			__asm__("mtdcr 240,4");
			break;
		case 241:
			__asm__("mtdcr 241,4");
			break;
		case 242:
			__asm__("mtdcr 242,4");
			break;
		case 243:
			__asm__("mtdcr 243,4");
			break;
		case 244:
			__asm__("mtdcr 244,4");
			break;
		case 245:
			__asm__("mtdcr 245,4");
			break;
		case 246:
			__asm__("mtdcr 246,4");
			break;
		case 247:
			__asm__("mtdcr 247,4");
			break;
		case 248:
			__asm__("mtdcr 248,4");
			break;
		case 249:
			__asm__("mtdcr 249,4");
			break;
		case 250:
			__asm__("mtdcr 250,4");
			break;
		case 251:
			__asm__("mtdcr 251,4");
			break;
		case 252:
			__asm__("mtdcr 252,4");
			break;
		case 253:
			__asm__("mtdcr 253,4");
			break;
		case 254:
			__asm__("mtdcr 254,4");
			break;
		case 255:
			__asm__("mtdcr 255,4");
			break;
		case 256:
			__asm__("mtdcr 256,4");
			break;
		case 257:
			__asm__("mtdcr 257,4");
			break;
		case 258:
			__asm__("mtdcr 258,4");
			break;
		case 259:
			__asm__("mtdcr 259,4");
			break;
		case 260:
			__asm__("mtdcr 260,4");
			break;
		case 261:
			__asm__("mtdcr 261,4");
			break;
		case 262:
			__asm__("mtdcr 262,4");
			break;
		case 263:
			__asm__("mtdcr 263,4");
			break;
		case 264:
			__asm__("mtdcr 264,4");
			break;
		case 265:
			__asm__("mtdcr 265,4");
			break;
		case 266:
			__asm__("mtdcr 266,4");
			break;
		case 267:
			__asm__("mtdcr 267,4");
			break;
		case 268:
			__asm__("mtdcr 268,4");
			break;
		case 269:
			__asm__("mtdcr 269,4");
			break;
		case 270:
			__asm__("mtdcr 270,4");
			break;
		case 271:
			__asm__("mtdcr 271,4");
			break;
		case 272:
			__asm__("mtdcr 272,4");
			break;
		case 273:
			__asm__("mtdcr 273,4");
			break;
		case 274:
			__asm__("mtdcr 274,4");
			break;
		case 275:
			__asm__("mtdcr 275,4");
			break;
		case 276:
			__asm__("mtdcr 276,4");
			break;
		case 277:
			__asm__("mtdcr 277,4");
			break;
		case 278:
			__asm__("mtdcr 278,4");
			break;
		case 279:
			__asm__("mtdcr 279,4");
			break;
		case 280:
			__asm__("mtdcr 280,4");
			break;
		case 281:
			__asm__("mtdcr 281,4");
			break;
		case 282:
			__asm__("mtdcr 282,4");
			break;
		case 283:
			__asm__("mtdcr 283,4");
			break;
		case 284:
			__asm__("mtdcr 284,4");
			break;
		case 285:
			__asm__("mtdcr 285,4");
			break;
		case 286:
			__asm__("mtdcr 286,4");
			break;
		case 287:
			__asm__("mtdcr 287,4");
			break;
		case 288:
			__asm__("mtdcr 288,4");
			break;
		case 289:
			__asm__("mtdcr 289,4");
			break;
		case 290:
			__asm__("mtdcr 290,4");
			break;
		case 291:
			__asm__("mtdcr 291,4");
			break;
		case 292:
			__asm__("mtdcr 292,4");
			break;
		case 293:
			__asm__("mtdcr 293,4");
			break;
		case 294:
			__asm__("mtdcr 294,4");
			break;
		case 295:
			__asm__("mtdcr 295,4");
			break;
		case 296:
			__asm__("mtdcr 296,4");
			break;
		case 297:
			__asm__("mtdcr 297,4");
			break;
		case 298:
			__asm__("mtdcr 298,4");
			break;
		case 299:
			__asm__("mtdcr 299,4");
			break;
		case 300:
			__asm__("mtdcr 300,4");
			break;
		case 301:
			__asm__("mtdcr 301,4");
			break;
		case 302:
			__asm__("mtdcr 302,4");
			break;
		case 303:
			__asm__("mtdcr 303,4");
			break;
		case 304:
			__asm__("mtdcr 304,4");
			break;
		case 305:
			__asm__("mtdcr 305,4");
			break;
		case 306:
			__asm__("mtdcr 306,4");
			break;
		case 307:
			__asm__("mtdcr 307,4");
			break;
		case 308:
			__asm__("mtdcr 308,4");
			break;
		case 309:
			__asm__("mtdcr 309,4");
			break;
		case 310:
			__asm__("mtdcr 310,4");
			break;
		case 311:
			__asm__("mtdcr 311,4");
			break;
		case 312:
			__asm__("mtdcr 312,4");
			break;
		case 313:
			__asm__("mtdcr 313,4");
			break;
		case 314:
			__asm__("mtdcr 314,4");
			break;
		case 315:
			__asm__("mtdcr 315,4");
			break;
		case 316:
			__asm__("mtdcr 316,4");
			break;
		case 317:
			__asm__("mtdcr 317,4");
			break;
		case 318:
			__asm__("mtdcr 318,4");
			break;
		case 319:
			__asm__("mtdcr 319,4");
			break;
		case 320:
			__asm__("mtdcr 320,4");
			break;
		case 321:
			__asm__("mtdcr 321,4");
			break;
		case 322:
			__asm__("mtdcr 322,4");
			break;
		case 323:
			__asm__("mtdcr 323,4");
			break;
		case 324:
			__asm__("mtdcr 324,4");
			break;
		case 325:
			__asm__("mtdcr 325,4");
			break;
		case 326:
			__asm__("mtdcr 326,4");
			break;
		case 327:
			__asm__("mtdcr 327,4");
			break;
		case 328:
			__asm__("mtdcr 328,4");
			break;
		case 329:
			__asm__("mtdcr 329,4");
			break;
		case 330:
			__asm__("mtdcr 330,4");
			break;
		case 331:
			__asm__("mtdcr 331,4");
			break;
		case 332:
			__asm__("mtdcr 332,4");
			break;
		case 333:
			__asm__("mtdcr 333,4");
			break;
		case 334:
			__asm__("mtdcr 334,4");
			break;
		case 335:
			__asm__("mtdcr 335,4");
			break;
		case 336:
			__asm__("mtdcr 336,4");
			break;
		case 337:
			__asm__("mtdcr 337,4");
			break;
		case 338:
			__asm__("mtdcr 338,4");
			break;
		case 339:
			__asm__("mtdcr 339,4");
			break;
		case 340:
			__asm__("mtdcr 340,4");
			break;
		case 341:
			__asm__("mtdcr 341,4");
			break;
		case 342:
			__asm__("mtdcr 342,4");
			break;
		case 343:
			__asm__("mtdcr 343,4");
			break;
		case 344:
			__asm__("mtdcr 344,4");
			break;
		case 345:
			__asm__("mtdcr 345,4");
			break;
		case 346:
			__asm__("mtdcr 346,4");
			break;
		case 347:
			__asm__("mtdcr 347,4");
			break;
		case 348:
			__asm__("mtdcr 348,4");
			break;
		case 349:
			__asm__("mtdcr 349,4");
			break;
		case 350:
			__asm__("mtdcr 350,4");
			break;
		case 351:
			__asm__("mtdcr 351,4");
			break;
		case 352:
			__asm__("mtdcr 352,4");
			break;
		case 353:
			__asm__("mtdcr 353,4");
			break;
		case 354:
			__asm__("mtdcr 354,4");
			break;
		case 355:
			__asm__("mtdcr 355,4");
			break;
		case 356:
			__asm__("mtdcr 356,4");
			break;
		case 357:
			__asm__("mtdcr 357,4");
			break;
		case 358:
			__asm__("mtdcr 358,4");
			break;
		case 359:
			__asm__("mtdcr 359,4");
			break;
		case 360:
			__asm__("mtdcr 360,4");
			break;
		case 361:
			__asm__("mtdcr 361,4");
			break;
		case 362:
			__asm__("mtdcr 362,4");
			break;
		case 363:
			__asm__("mtdcr 363,4");
			break;
		case 364:
			__asm__("mtdcr 364,4");
			break;
		case 365:
			__asm__("mtdcr 365,4");
			break;
		case 366:
			__asm__("mtdcr 366,4");
			break;
		case 367:
			__asm__("mtdcr 367,4");
			break;
		case 368:
			__asm__("mtdcr 368,4");
			break;
		case 369:
			__asm__("mtdcr 369,4");
			break;
		case 370:
			__asm__("mtdcr 370,4");
			break;
		case 371:
			__asm__("mtdcr 371,4");
			break;
		case 372:
			__asm__("mtdcr 372,4");
			break;
		case 373:
			__asm__("mtdcr 373,4");
			break;
		case 374:
			__asm__("mtdcr 374,4");
			break;
		case 375:
			__asm__("mtdcr 375,4");
			break;
		case 376:
			__asm__("mtdcr 376,4");
			break;
		case 377:
			__asm__("mtdcr 377,4");
			break;
		case 378:
			__asm__("mtdcr 378,4");
			break;
		case 379:
			__asm__("mtdcr 379,4");
			break;
		case 380:
			__asm__("mtdcr 380,4");
			break;
		case 381:
			__asm__("mtdcr 381,4");
			break;
		case 382:
			__asm__("mtdcr 382,4");
			break;
		case 383:
			__asm__("mtdcr 383,4");
			break;
		case 384:
			__asm__("mtdcr 384,4");
			break;
		case 385:
			__asm__("mtdcr 385,4");
			break;
		case 386:
			__asm__("mtdcr 386,4");
			break;
		case 387:
			__asm__("mtdcr 387,4");
			break;
		case 388:
			__asm__("mtdcr 388,4");
			break;
		case 389:
			__asm__("mtdcr 389,4");
			break;
		case 390:
			__asm__("mtdcr 390,4");
			break;
		case 391:
			__asm__("mtdcr 391,4");
			break;
		case 392:
			__asm__("mtdcr 392,4");
			break;
		case 393:
			__asm__("mtdcr 393,4");
			break;
		case 394:
			__asm__("mtdcr 394,4");
			break;
		case 395:
			__asm__("mtdcr 395,4");
			break;
		case 396:
			__asm__("mtdcr 396,4");
			break;
		case 397:
			__asm__("mtdcr 397,4");
			break;
		case 398:
			__asm__("mtdcr 398,4");
			break;
		case 399:
			__asm__("mtdcr 399,4");
			break;
		case 400:
			__asm__("mtdcr 400,4");
			break;
		case 401:
			__asm__("mtdcr 401,4");
			break;
		case 402:
			__asm__("mtdcr 402,4");
			break;
		case 403:
			__asm__("mtdcr 403,4");
			break;
		case 404:
			__asm__("mtdcr 404,4");
			break;
		case 405:
			__asm__("mtdcr 405,4");
			break;
		case 406:
			__asm__("mtdcr 406,4");
			break;
		case 407:
			__asm__("mtdcr 407,4");
			break;
		case 408:
			__asm__("mtdcr 408,4");
			break;
		case 409:
			__asm__("mtdcr 409,4");
			break;
		case 410:
			__asm__("mtdcr 410,4");
			break;
		case 411:
			__asm__("mtdcr 411,4");
			break;
		case 412:
			__asm__("mtdcr 412,4");
			break;
		case 413:
			__asm__("mtdcr 413,4");
			break;
		case 414:
			__asm__("mtdcr 414,4");
			break;
		case 415:
			__asm__("mtdcr 415,4");
			break;
		case 416:
			__asm__("mtdcr 416,4");
			break;
		case 417:
			__asm__("mtdcr 417,4");
			break;
		case 418:
			__asm__("mtdcr 418,4");
			break;
		case 419:
			__asm__("mtdcr 419,4");
			break;
		case 420:
			__asm__("mtdcr 420,4");
			break;
		case 421:
			__asm__("mtdcr 421,4");
			break;
		case 422:
			__asm__("mtdcr 422,4");
			break;
		case 423:
			__asm__("mtdcr 423,4");
			break;
		case 424:
			__asm__("mtdcr 424,4");
			break;
		case 425:
			__asm__("mtdcr 425,4");
			break;
		case 426:
			__asm__("mtdcr 426,4");
			break;
		case 427:
			__asm__("mtdcr 427,4");
			break;
		case 428:
			__asm__("mtdcr 428,4");
			break;
		case 429:
			__asm__("mtdcr 429,4");
			break;
		case 430:
			__asm__("mtdcr 430,4");
			break;
		case 431:
			__asm__("mtdcr 431,4");
			break;
		case 432:
			__asm__("mtdcr 432,4");
			break;
		case 433:
			__asm__("mtdcr 433,4");
			break;
		case 434:
			__asm__("mtdcr 434,4");
			break;
		case 435:
			__asm__("mtdcr 435,4");
			break;
		case 436:
			__asm__("mtdcr 436,4");
			break;
		case 437:
			__asm__("mtdcr 437,4");
			break;
		case 438:
			__asm__("mtdcr 438,4");
			break;
		case 439:
			__asm__("mtdcr 439,4");
			break;
		case 440:
			__asm__("mtdcr 440,4");
			break;
		case 441:
			__asm__("mtdcr 441,4");
			break;
		case 442:
			__asm__("mtdcr 442,4");
			break;
		case 443:
			__asm__("mtdcr 443,4");
			break;
		case 444:
			__asm__("mtdcr 444,4");
			break;
		case 445:
			__asm__("mtdcr 445,4");
			break;
		case 446:
			__asm__("mtdcr 446,4");
			break;
		case 447:
			__asm__("mtdcr 447,4");
			break;
		case 448:
			__asm__("mtdcr 448,4");
			break;
		case 449:
			__asm__("mtdcr 449,4");
			break;
		case 450:
			__asm__("mtdcr 450,4");
			break;
		case 451:
			__asm__("mtdcr 451,4");
			break;
		case 452:
			__asm__("mtdcr 452,4");
			break;
		case 453:
			__asm__("mtdcr 453,4");
			break;
		case 454:
			__asm__("mtdcr 454,4");
			break;
		case 455:
			__asm__("mtdcr 455,4");
			break;
		case 456:
			__asm__("mtdcr 456,4");
			break;
		case 457:
			__asm__("mtdcr 457,4");
			break;
		case 458:
			__asm__("mtdcr 458,4");
			break;
		case 459:
			__asm__("mtdcr 459,4");
			break;
		case 460:
			__asm__("mtdcr 460,4");
			break;
		case 461:
			__asm__("mtdcr 461,4");
			break;
		case 462:
			__asm__("mtdcr 462,4");
			break;
		case 463:
			__asm__("mtdcr 463,4");
			break;
		case 464:
			__asm__("mtdcr 464,4");
			break;
		case 465:
			__asm__("mtdcr 465,4");
			break;
		case 466:
			__asm__("mtdcr 466,4");
			break;
		case 467:
			__asm__("mtdcr 467,4");
			break;
		case 468:
			__asm__("mtdcr 468,4");
			break;
		case 469:
			__asm__("mtdcr 469,4");
			break;
		case 470:
			__asm__("mtdcr 470,4");
			break;
		case 471:
			__asm__("mtdcr 471,4");
			break;
		case 472:
			__asm__("mtdcr 472,4");
			break;
		case 473:
			__asm__("mtdcr 473,4");
			break;
		case 474:
			__asm__("mtdcr 474,4");
			break;
		case 475:
			__asm__("mtdcr 475,4");
			break;
		case 476:
			__asm__("mtdcr 476,4");
			break;
		case 477:
			__asm__("mtdcr 477,4");
			break;
		case 478:
			__asm__("mtdcr 478,4");
			break;
		case 479:
			__asm__("mtdcr 479,4");
			break;
		case 480:
			__asm__("mtdcr 480,4");
			break;
		case 481:
			__asm__("mtdcr 481,4");
			break;
		case 482:
			__asm__("mtdcr 482,4");
			break;
		case 483:
			__asm__("mtdcr 483,4");
			break;
		case 484:
			__asm__("mtdcr 484,4");
			break;
		case 485:
			__asm__("mtdcr 485,4");
			break;
		case 486:
			__asm__("mtdcr 486,4");
			break;
		case 487:
			__asm__("mtdcr 487,4");
			break;
		case 488:
			__asm__("mtdcr 488,4");
			break;
		case 489:
			__asm__("mtdcr 489,4");
			break;
		case 490:
			__asm__("mtdcr 490,4");
			break;
		case 491:
			__asm__("mtdcr 491,4");
			break;
		case 492:
			__asm__("mtdcr 492,4");
			break;
		case 493:
			__asm__("mtdcr 493,4");
			break;
		case 494:
			__asm__("mtdcr 494,4");
			break;
		case 495:
			__asm__("mtdcr 495,4");
			break;
		case 496:
			__asm__("mtdcr 496,4");
			break;
		case 497:
			__asm__("mtdcr 497,4");
			break;
		case 498:
			__asm__("mtdcr 498,4");
			break;
		case 499:
			__asm__("mtdcr 499,4");
			break;
		case 500:
			__asm__("mtdcr 500,4");
			break;
		case 501:
			__asm__("mtdcr 501,4");
			break;
		case 502:
			__asm__("mtdcr 502,4");
			break;
		case 503:
			__asm__("mtdcr 503,4");
			break;
		case 504:
			__asm__("mtdcr 504,4");
			break;
		case 505:
			__asm__("mtdcr 505,4");
			break;
		case 506:
			__asm__("mtdcr 506,4");
			break;
		case 507:
			__asm__("mtdcr 507,4");
			break;
		case 508:
			__asm__("mtdcr 508,4");
			break;
		case 509:
			__asm__("mtdcr 509,4");
			break;
		case 510:
			__asm__("mtdcr 510,4");
			break;
		case 511:
			__asm__("mtdcr 511,4");
			break;
		case 512:
			__asm__("mtdcr 512,4");
			break;
		case 513:
			__asm__("mtdcr 513,4");
			break;
		case 514:
			__asm__("mtdcr 514,4");
			break;
		case 515:
			__asm__("mtdcr 515,4");
			break;
		case 516:
			__asm__("mtdcr 516,4");
			break;
		case 517:
			__asm__("mtdcr 517,4");
			break;
		case 518:
			__asm__("mtdcr 518,4");
			break;
		case 519:
			__asm__("mtdcr 519,4");
			break;
		case 520:
			__asm__("mtdcr 520,4");
			break;
		case 521:
			__asm__("mtdcr 521,4");
			break;
		case 522:
			__asm__("mtdcr 522,4");
			break;
		case 523:
			__asm__("mtdcr 523,4");
			break;
		case 524:
			__asm__("mtdcr 524,4");
			break;
		case 525:
			__asm__("mtdcr 525,4");
			break;
		case 526:
			__asm__("mtdcr 526,4");
			break;
		case 527:
			__asm__("mtdcr 527,4");
			break;
		case 528:
			__asm__("mtdcr 528,4");
			break;
		case 529:
			__asm__("mtdcr 529,4");
			break;
		case 530:
			__asm__("mtdcr 530,4");
			break;
		case 531:
			__asm__("mtdcr 531,4");
			break;
		case 532:
			__asm__("mtdcr 532,4");
			break;
		case 533:
			__asm__("mtdcr 533,4");
			break;
		case 534:
			__asm__("mtdcr 534,4");
			break;
		case 535:
			__asm__("mtdcr 535,4");
			break;
		case 536:
			__asm__("mtdcr 536,4");
			break;
		case 537:
			__asm__("mtdcr 537,4");
			break;
		case 538:
			__asm__("mtdcr 538,4");
			break;
		case 539:
			__asm__("mtdcr 539,4");
			break;
		case 540:
			__asm__("mtdcr 540,4");
			break;
		case 541:
			__asm__("mtdcr 541,4");
			break;
		case 542:
			__asm__("mtdcr 542,4");
			break;
		case 543:
			__asm__("mtdcr 543,4");
			break;
		case 544:
			__asm__("mtdcr 544,4");
			break;
		case 545:
			__asm__("mtdcr 545,4");
			break;
		case 546:
			__asm__("mtdcr 546,4");
			break;
		case 547:
			__asm__("mtdcr 547,4");
			break;
		case 548:
			__asm__("mtdcr 548,4");
			break;
		case 549:
			__asm__("mtdcr 549,4");
			break;
		case 550:
			__asm__("mtdcr 550,4");
			break;
		case 551:
			__asm__("mtdcr 551,4");
			break;
		case 552:
			__asm__("mtdcr 552,4");
			break;
		case 553:
			__asm__("mtdcr 553,4");
			break;
		case 554:
			__asm__("mtdcr 554,4");
			break;
		case 555:
			__asm__("mtdcr 555,4");
			break;
		case 556:
			__asm__("mtdcr 556,4");
			break;
		case 557:
			__asm__("mtdcr 557,4");
			break;
		case 558:
			__asm__("mtdcr 558,4");
			break;
		case 559:
			__asm__("mtdcr 559,4");
			break;
		case 560:
			__asm__("mtdcr 560,4");
			break;
		case 561:
			__asm__("mtdcr 561,4");
			break;
		case 562:
			__asm__("mtdcr 562,4");
			break;
		case 563:
			__asm__("mtdcr 563,4");
			break;
		case 564:
			__asm__("mtdcr 564,4");
			break;
		case 565:
			__asm__("mtdcr 565,4");
			break;
		case 566:
			__asm__("mtdcr 566,4");
			break;
		case 567:
			__asm__("mtdcr 567,4");
			break;
		case 568:
			__asm__("mtdcr 568,4");
			break;
		case 569:
			__asm__("mtdcr 569,4");
			break;
		case 570:
			__asm__("mtdcr 570,4");
			break;
		case 571:
			__asm__("mtdcr 571,4");
			break;
		case 572:
			__asm__("mtdcr 572,4");
			break;
		case 573:
			__asm__("mtdcr 573,4");
			break;
		case 574:
			__asm__("mtdcr 574,4");
			break;
		case 575:
			__asm__("mtdcr 575,4");
			break;
		case 576:
			__asm__("mtdcr 576,4");
			break;
		case 577:
			__asm__("mtdcr 577,4");
			break;
		case 578:
			__asm__("mtdcr 578,4");
			break;
		case 579:
			__asm__("mtdcr 579,4");
			break;
		case 580:
			__asm__("mtdcr 580,4");
			break;
		case 581:
			__asm__("mtdcr 581,4");
			break;
		case 582:
			__asm__("mtdcr 582,4");
			break;
		case 583:
			__asm__("mtdcr 583,4");
			break;
		case 584:
			__asm__("mtdcr 584,4");
			break;
		case 585:
			__asm__("mtdcr 585,4");
			break;
		case 586:
			__asm__("mtdcr 586,4");
			break;
		case 587:
			__asm__("mtdcr 587,4");
			break;
		case 588:
			__asm__("mtdcr 588,4");
			break;
		case 589:
			__asm__("mtdcr 589,4");
			break;
		case 590:
			__asm__("mtdcr 590,4");
			break;
		case 591:
			__asm__("mtdcr 591,4");
			break;
		case 592:
			__asm__("mtdcr 592,4");
			break;
		case 593:
			__asm__("mtdcr 593,4");
			break;
		case 594:
			__asm__("mtdcr 594,4");
			break;
		case 595:
			__asm__("mtdcr 595,4");
			break;
		case 596:
			__asm__("mtdcr 596,4");
			break;
		case 597:
			__asm__("mtdcr 597,4");
			break;
		case 598:
			__asm__("mtdcr 598,4");
			break;
		case 599:
			__asm__("mtdcr 599,4");
			break;
		case 600:
			__asm__("mtdcr 600,4");
			break;
		case 601:
			__asm__("mtdcr 601,4");
			break;
		case 602:
			__asm__("mtdcr 602,4");
			break;
		case 603:
			__asm__("mtdcr 603,4");
			break;
		case 604:
			__asm__("mtdcr 604,4");
			break;
		case 605:
			__asm__("mtdcr 605,4");
			break;
		case 606:
			__asm__("mtdcr 606,4");
			break;
		case 607:
			__asm__("mtdcr 607,4");
			break;
		case 608:
			__asm__("mtdcr 608,4");
			break;
		case 609:
			__asm__("mtdcr 609,4");
			break;
		case 610:
			__asm__("mtdcr 610,4");
			break;
		case 611:
			__asm__("mtdcr 611,4");
			break;
		case 612:
			__asm__("mtdcr 612,4");
			break;
		case 613:
			__asm__("mtdcr 613,4");
			break;
		case 614:
			__asm__("mtdcr 614,4");
			break;
		case 615:
			__asm__("mtdcr 615,4");
			break;
		case 616:
			__asm__("mtdcr 616,4");
			break;
		case 617:
			__asm__("mtdcr 617,4");
			break;
		case 618:
			__asm__("mtdcr 618,4");
			break;
		case 619:
			__asm__("mtdcr 619,4");
			break;
		case 620:
			__asm__("mtdcr 620,4");
			break;
		case 621:
			__asm__("mtdcr 621,4");
			break;
		case 622:
			__asm__("mtdcr 622,4");
			break;
		case 623:
			__asm__("mtdcr 623,4");
			break;
		case 624:
			__asm__("mtdcr 624,4");
			break;
		case 625:
			__asm__("mtdcr 625,4");
			break;
		case 626:
			__asm__("mtdcr 626,4");
			break;
		case 627:
			__asm__("mtdcr 627,4");
			break;
		case 628:
			__asm__("mtdcr 628,4");
			break;
		case 629:
			__asm__("mtdcr 629,4");
			break;
		case 630:
			__asm__("mtdcr 630,4");
			break;
		case 631:
			__asm__("mtdcr 631,4");
			break;
		case 632:
			__asm__("mtdcr 632,4");
			break;
		case 633:
			__asm__("mtdcr 633,4");
			break;
		case 634:
			__asm__("mtdcr 634,4");
			break;
		case 635:
			__asm__("mtdcr 635,4");
			break;
		case 636:
			__asm__("mtdcr 636,4");
			break;
		case 637:
			__asm__("mtdcr 637,4");
			break;
		case 638:
			__asm__("mtdcr 638,4");
			break;
		case 639:
			__asm__("mtdcr 639,4");
			break;
		case 640:
			__asm__("mtdcr 640,4");
			break;
		case 641:
			__asm__("mtdcr 641,4");
			break;
		case 642:
			__asm__("mtdcr 642,4");
			break;
		case 643:
			__asm__("mtdcr 643,4");
			break;
		case 644:
			__asm__("mtdcr 644,4");
			break;
		case 645:
			__asm__("mtdcr 645,4");
			break;
		case 646:
			__asm__("mtdcr 646,4");
			break;
		case 647:
			__asm__("mtdcr 647,4");
			break;
		case 648:
			__asm__("mtdcr 648,4");
			break;
		case 649:
			__asm__("mtdcr 649,4");
			break;
		case 650:
			__asm__("mtdcr 650,4");
			break;
		case 651:
			__asm__("mtdcr 651,4");
			break;
		case 652:
			__asm__("mtdcr 652,4");
			break;
		case 653:
			__asm__("mtdcr 653,4");
			break;
		case 654:
			__asm__("mtdcr 654,4");
			break;
		case 655:
			__asm__("mtdcr 655,4");
			break;
		case 656:
			__asm__("mtdcr 656,4");
			break;
		case 657:
			__asm__("mtdcr 657,4");
			break;
		case 658:
			__asm__("mtdcr 658,4");
			break;
		case 659:
			__asm__("mtdcr 659,4");
			break;
		case 660:
			__asm__("mtdcr 660,4");
			break;
		case 661:
			__asm__("mtdcr 661,4");
			break;
		case 662:
			__asm__("mtdcr 662,4");
			break;
		case 663:
			__asm__("mtdcr 663,4");
			break;
		case 664:
			__asm__("mtdcr 664,4");
			break;
		case 665:
			__asm__("mtdcr 665,4");
			break;
		case 666:
			__asm__("mtdcr 666,4");
			break;
		case 667:
			__asm__("mtdcr 667,4");
			break;
		case 668:
			__asm__("mtdcr 668,4");
			break;
		case 669:
			__asm__("mtdcr 669,4");
			break;
		case 670:
			__asm__("mtdcr 670,4");
			break;
		case 671:
			__asm__("mtdcr 671,4");
			break;
		case 672:
			__asm__("mtdcr 672,4");
			break;
		case 673:
			__asm__("mtdcr 673,4");
			break;
		case 674:
			__asm__("mtdcr 674,4");
			break;
		case 675:
			__asm__("mtdcr 675,4");
			break;
		case 676:
			__asm__("mtdcr 676,4");
			break;
		case 677:
			__asm__("mtdcr 677,4");
			break;
		case 678:
			__asm__("mtdcr 678,4");
			break;
		case 679:
			__asm__("mtdcr 679,4");
			break;
		case 680:
			__asm__("mtdcr 680,4");
			break;
		case 681:
			__asm__("mtdcr 681,4");
			break;
		case 682:
			__asm__("mtdcr 682,4");
			break;
		case 683:
			__asm__("mtdcr 683,4");
			break;
		case 684:
			__asm__("mtdcr 684,4");
			break;
		case 685:
			__asm__("mtdcr 685,4");
			break;
		case 686:
			__asm__("mtdcr 686,4");
			break;
		case 687:
			__asm__("mtdcr 687,4");
			break;
		case 688:
			__asm__("mtdcr 688,4");
			break;
		case 689:
			__asm__("mtdcr 689,4");
			break;
		case 690:
			__asm__("mtdcr 690,4");
			break;
		case 691:
			__asm__("mtdcr 691,4");
			break;
		case 692:
			__asm__("mtdcr 692,4");
			break;
		case 693:
			__asm__("mtdcr 693,4");
			break;
		case 694:
			__asm__("mtdcr 694,4");
			break;
		case 695:
			__asm__("mtdcr 695,4");
			break;
		case 696:
			__asm__("mtdcr 696,4");
			break;
		case 697:
			__asm__("mtdcr 697,4");
			break;
		case 698:
			__asm__("mtdcr 698,4");
			break;
		case 699:
			__asm__("mtdcr 699,4");
			break;
		case 700:
			__asm__("mtdcr 700,4");
			break;
		case 701:
			__asm__("mtdcr 701,4");
			break;
		case 702:
			__asm__("mtdcr 702,4");
			break;
		case 703:
			__asm__("mtdcr 703,4");
			break;
		case 704:
			__asm__("mtdcr 704,4");
			break;
		case 705:
			__asm__("mtdcr 705,4");
			break;
		case 706:
			__asm__("mtdcr 706,4");
			break;
		case 707:
			__asm__("mtdcr 707,4");
			break;
		case 708:
			__asm__("mtdcr 708,4");
			break;
		case 709:
			__asm__("mtdcr 709,4");
			break;
		case 710:
			__asm__("mtdcr 710,4");
			break;
		case 711:
			__asm__("mtdcr 711,4");
			break;
		case 712:
			__asm__("mtdcr 712,4");
			break;
		case 713:
			__asm__("mtdcr 713,4");
			break;
		case 714:
			__asm__("mtdcr 714,4");
			break;
		case 715:
			__asm__("mtdcr 715,4");
			break;
		case 716:
			__asm__("mtdcr 716,4");
			break;
		case 717:
			__asm__("mtdcr 717,4");
			break;
		case 718:
			__asm__("mtdcr 718,4");
			break;
		case 719:
			__asm__("mtdcr 719,4");
			break;
		case 720:
			__asm__("mtdcr 720,4");
			break;
		case 721:
			__asm__("mtdcr 721,4");
			break;
		case 722:
			__asm__("mtdcr 722,4");
			break;
		case 723:
			__asm__("mtdcr 723,4");
			break;
		case 724:
			__asm__("mtdcr 724,4");
			break;
		case 725:
			__asm__("mtdcr 725,4");
			break;
		case 726:
			__asm__("mtdcr 726,4");
			break;
		case 727:
			__asm__("mtdcr 727,4");
			break;
		case 728:
			__asm__("mtdcr 728,4");
			break;
		case 729:
			__asm__("mtdcr 729,4");
			break;
		case 730:
			__asm__("mtdcr 730,4");
			break;
		case 731:
			__asm__("mtdcr 731,4");
			break;
		case 732:
			__asm__("mtdcr 732,4");
			break;
		case 733:
			__asm__("mtdcr 733,4");
			break;
		case 734:
			__asm__("mtdcr 734,4");
			break;
		case 735:
			__asm__("mtdcr 735,4");
			break;
		case 736:
			__asm__("mtdcr 736,4");
			break;
		case 737:
			__asm__("mtdcr 737,4");
			break;
		case 738:
			__asm__("mtdcr 738,4");
			break;
		case 739:
			__asm__("mtdcr 739,4");
			break;
		case 740:
			__asm__("mtdcr 740,4");
			break;
		case 741:
			__asm__("mtdcr 741,4");
			break;
		case 742:
			__asm__("mtdcr 742,4");
			break;
		case 743:
			__asm__("mtdcr 743,4");
			break;
		case 744:
			__asm__("mtdcr 744,4");
			break;
		case 745:
			__asm__("mtdcr 745,4");
			break;
		case 746:
			__asm__("mtdcr 746,4");
			break;
		case 747:
			__asm__("mtdcr 747,4");
			break;
		case 748:
			__asm__("mtdcr 748,4");
			break;
		case 749:
			__asm__("mtdcr 749,4");
			break;
		case 750:
			__asm__("mtdcr 750,4");
			break;
		case 751:
			__asm__("mtdcr 751,4");
			break;
		case 752:
			__asm__("mtdcr 752,4");
			break;
		case 753:
			__asm__("mtdcr 753,4");
			break;
		case 754:
			__asm__("mtdcr 754,4");
			break;
		case 755:
			__asm__("mtdcr 755,4");
			break;
		case 756:
			__asm__("mtdcr 756,4");
			break;
		case 757:
			__asm__("mtdcr 757,4");
			break;
		case 758:
			__asm__("mtdcr 758,4");
			break;
		case 759:
			__asm__("mtdcr 759,4");
			break;
		case 760:
			__asm__("mtdcr 760,4");
			break;
		case 761:
			__asm__("mtdcr 761,4");
			break;
		case 762:
			__asm__("mtdcr 762,4");
			break;
		case 763:
			__asm__("mtdcr 763,4");
			break;
		case 764:
			__asm__("mtdcr 764,4");
			break;
		case 765:
			__asm__("mtdcr 765,4");
			break;
		case 766:
			__asm__("mtdcr 766,4");
			break;
		case 767:
			__asm__("mtdcr 767,4");
			break;
		case 768:
			__asm__("mtdcr 768,4");
			break;
		case 769:
			__asm__("mtdcr 769,4");
			break;
		case 770:
			__asm__("mtdcr 770,4");
			break;
		case 771:
			__asm__("mtdcr 771,4");
			break;
		case 772:
			__asm__("mtdcr 772,4");
			break;
		case 773:
			__asm__("mtdcr 773,4");
			break;
		case 774:
			__asm__("mtdcr 774,4");
			break;
		case 775:
			__asm__("mtdcr 775,4");
			break;
		case 776:
			__asm__("mtdcr 776,4");
			break;
		case 777:
			__asm__("mtdcr 777,4");
			break;
		case 778:
			__asm__("mtdcr 778,4");
			break;
		case 779:
			__asm__("mtdcr 779,4");
			break;
		case 780:
			__asm__("mtdcr 780,4");
			break;
		case 781:
			__asm__("mtdcr 781,4");
			break;
		case 782:
			__asm__("mtdcr 782,4");
			break;
		case 783:
			__asm__("mtdcr 783,4");
			break;
		case 784:
			__asm__("mtdcr 784,4");
			break;
		case 785:
			__asm__("mtdcr 785,4");
			break;
		case 786:
			__asm__("mtdcr 786,4");
			break;
		case 787:
			__asm__("mtdcr 787,4");
			break;
		case 788:
			__asm__("mtdcr 788,4");
			break;
		case 789:
			__asm__("mtdcr 789,4");
			break;
		case 790:
			__asm__("mtdcr 790,4");
			break;
		case 791:
			__asm__("mtdcr 791,4");
			break;
		case 792:
			__asm__("mtdcr 792,4");
			break;
		case 793:
			__asm__("mtdcr 793,4");
			break;
		case 794:
			__asm__("mtdcr 794,4");
			break;
		case 795:
			__asm__("mtdcr 795,4");
			break;
		case 796:
			__asm__("mtdcr 796,4");
			break;
		case 797:
			__asm__("mtdcr 797,4");
			break;
		case 798:
			__asm__("mtdcr 798,4");
			break;
		case 799:
			__asm__("mtdcr 799,4");
			break;
		case 800:
			__asm__("mtdcr 800,4");
			break;
		case 801:
			__asm__("mtdcr 801,4");
			break;
		case 802:
			__asm__("mtdcr 802,4");
			break;
		case 803:
			__asm__("mtdcr 803,4");
			break;
		case 804:
			__asm__("mtdcr 804,4");
			break;
		case 805:
			__asm__("mtdcr 805,4");
			break;
		case 806:
			__asm__("mtdcr 806,4");
			break;
		case 807:
			__asm__("mtdcr 807,4");
			break;
		case 808:
			__asm__("mtdcr 808,4");
			break;
		case 809:
			__asm__("mtdcr 809,4");
			break;
		case 810:
			__asm__("mtdcr 810,4");
			break;
		case 811:
			__asm__("mtdcr 811,4");
			break;
		case 812:
			__asm__("mtdcr 812,4");
			break;
		case 813:
			__asm__("mtdcr 813,4");
			break;
		case 814:
			__asm__("mtdcr 814,4");
			break;
		case 815:
			__asm__("mtdcr 815,4");
			break;
		case 816:
			__asm__("mtdcr 816,4");
			break;
		case 817:
			__asm__("mtdcr 817,4");
			break;
		case 818:
			__asm__("mtdcr 818,4");
			break;
		case 819:
			__asm__("mtdcr 819,4");
			break;
		case 820:
			__asm__("mtdcr 820,4");
			break;
		case 821:
			__asm__("mtdcr 821,4");
			break;
		case 822:
			__asm__("mtdcr 822,4");
			break;
		case 823:
			__asm__("mtdcr 823,4");
			break;
		case 824:
			__asm__("mtdcr 824,4");
			break;
		case 825:
			__asm__("mtdcr 825,4");
			break;
		case 826:
			__asm__("mtdcr 826,4");
			break;
		case 827:
			__asm__("mtdcr 827,4");
			break;
		case 828:
			__asm__("mtdcr 828,4");
			break;
		case 829:
			__asm__("mtdcr 829,4");
			break;
		case 830:
			__asm__("mtdcr 830,4");
			break;
		case 831:
			__asm__("mtdcr 831,4");
			break;
		case 832:
			__asm__("mtdcr 832,4");
			break;
		case 833:
			__asm__("mtdcr 833,4");
			break;
		case 834:
			__asm__("mtdcr 834,4");
			break;
		case 835:
			__asm__("mtdcr 835,4");
			break;
		case 836:
			__asm__("mtdcr 836,4");
			break;
		case 837:
			__asm__("mtdcr 837,4");
			break;
		case 838:
			__asm__("mtdcr 838,4");
			break;
		case 839:
			__asm__("mtdcr 839,4");
			break;
		case 840:
			__asm__("mtdcr 840,4");
			break;
		case 841:
			__asm__("mtdcr 841,4");
			break;
		case 842:
			__asm__("mtdcr 842,4");
			break;
		case 843:
			__asm__("mtdcr 843,4");
			break;
		case 844:
			__asm__("mtdcr 844,4");
			break;
		case 845:
			__asm__("mtdcr 845,4");
			break;
		case 846:
			__asm__("mtdcr 846,4");
			break;
		case 847:
			__asm__("mtdcr 847,4");
			break;
		case 848:
			__asm__("mtdcr 848,4");
			break;
		case 849:
			__asm__("mtdcr 849,4");
			break;
		case 850:
			__asm__("mtdcr 850,4");
			break;
		case 851:
			__asm__("mtdcr 851,4");
			break;
		case 852:
			__asm__("mtdcr 852,4");
			break;
		case 853:
			__asm__("mtdcr 853,4");
			break;
		case 854:
			__asm__("mtdcr 854,4");
			break;
		case 855:
			__asm__("mtdcr 855,4");
			break;
		case 856:
			__asm__("mtdcr 856,4");
			break;
		case 857:
			__asm__("mtdcr 857,4");
			break;
		case 858:
			__asm__("mtdcr 858,4");
			break;
		case 859:
			__asm__("mtdcr 859,4");
			break;
		case 860:
			__asm__("mtdcr 860,4");
			break;
		case 861:
			__asm__("mtdcr 861,4");
			break;
		case 862:
			__asm__("mtdcr 862,4");
			break;
		case 863:
			__asm__("mtdcr 863,4");
			break;
		case 864:
			__asm__("mtdcr 864,4");
			break;
		case 865:
			__asm__("mtdcr 865,4");
			break;
		case 866:
			__asm__("mtdcr 866,4");
			break;
		case 867:
			__asm__("mtdcr 867,4");
			break;
		case 868:
			__asm__("mtdcr 868,4");
			break;
		case 869:
			__asm__("mtdcr 869,4");
			break;
		case 870:
			__asm__("mtdcr 870,4");
			break;
		case 871:
			__asm__("mtdcr 871,4");
			break;
		case 872:
			__asm__("mtdcr 872,4");
			break;
		case 873:
			__asm__("mtdcr 873,4");
			break;
		case 874:
			__asm__("mtdcr 874,4");
			break;
		case 875:
			__asm__("mtdcr 875,4");
			break;
		case 876:
			__asm__("mtdcr 876,4");
			break;
		case 877:
			__asm__("mtdcr 877,4");
			break;
		case 878:
			__asm__("mtdcr 878,4");
			break;
		case 879:
			__asm__("mtdcr 879,4");
			break;
		case 880:
			__asm__("mtdcr 880,4");
			break;
		case 881:
			__asm__("mtdcr 881,4");
			break;
		case 882:
			__asm__("mtdcr 882,4");
			break;
		case 883:
			__asm__("mtdcr 883,4");
			break;
		case 884:
			__asm__("mtdcr 884,4");
			break;
		case 885:
			__asm__("mtdcr 885,4");
			break;
		case 886:
			__asm__("mtdcr 886,4");
			break;
		case 887:
			__asm__("mtdcr 887,4");
			break;
		case 888:
			__asm__("mtdcr 888,4");
			break;
		case 889:
			__asm__("mtdcr 889,4");
			break;
		case 890:
			__asm__("mtdcr 890,4");
			break;
		case 891:
			__asm__("mtdcr 891,4");
			break;
		case 892:
			__asm__("mtdcr 892,4");
			break;
		case 893:
			__asm__("mtdcr 893,4");
			break;
		case 894:
			__asm__("mtdcr 894,4");
			break;
		case 895:
			__asm__("mtdcr 895,4");
			break;
		case 896:
			__asm__("mtdcr 896,4");
			break;
		case 897:
			__asm__("mtdcr 897,4");
			break;
		case 898:
			__asm__("mtdcr 898,4");
			break;
		case 899:
			__asm__("mtdcr 899,4");
			break;
		case 900:
			__asm__("mtdcr 900,4");
			break;
		case 901:
			__asm__("mtdcr 901,4");
			break;
		case 902:
			__asm__("mtdcr 902,4");
			break;
		case 903:
			__asm__("mtdcr 903,4");
			break;
		case 904:
			__asm__("mtdcr 904,4");
			break;
		case 905:
			__asm__("mtdcr 905,4");
			break;
		case 906:
			__asm__("mtdcr 906,4");
			break;
		case 907:
			__asm__("mtdcr 907,4");
			break;
		case 908:
			__asm__("mtdcr 908,4");
			break;
		case 909:
			__asm__("mtdcr 909,4");
			break;
		case 910:
			__asm__("mtdcr 910,4");
			break;
		case 911:
			__asm__("mtdcr 911,4");
			break;
		case 912:
			__asm__("mtdcr 912,4");
			break;
		case 913:
			__asm__("mtdcr 913,4");
			break;
		case 914:
			__asm__("mtdcr 914,4");
			break;
		case 915:
			__asm__("mtdcr 915,4");
			break;
		case 916:
			__asm__("mtdcr 916,4");
			break;
		case 917:
			__asm__("mtdcr 917,4");
			break;
		case 918:
			__asm__("mtdcr 918,4");
			break;
		case 919:
			__asm__("mtdcr 919,4");
			break;
		case 920:
			__asm__("mtdcr 920,4");
			break;
		case 921:
			__asm__("mtdcr 921,4");
			break;
		case 922:
			__asm__("mtdcr 922,4");
			break;
		case 923:
			__asm__("mtdcr 923,4");
			break;
		case 924:
			__asm__("mtdcr 924,4");
			break;
		case 925:
			__asm__("mtdcr 925,4");
			break;
		case 926:
			__asm__("mtdcr 926,4");
			break;
		case 927:
			__asm__("mtdcr 927,4");
			break;
		case 928:
			__asm__("mtdcr 928,4");
			break;
		case 929:
			__asm__("mtdcr 929,4");
			break;
		case 930:
			__asm__("mtdcr 930,4");
			break;
		case 931:
			__asm__("mtdcr 931,4");
			break;
		case 932:
			__asm__("mtdcr 932,4");
			break;
		case 933:
			__asm__("mtdcr 933,4");
			break;
		case 934:
			__asm__("mtdcr 934,4");
			break;
		case 935:
			__asm__("mtdcr 935,4");
			break;
		case 936:
			__asm__("mtdcr 936,4");
			break;
		case 937:
			__asm__("mtdcr 937,4");
			break;
		case 938:
			__asm__("mtdcr 938,4");
			break;
		case 939:
			__asm__("mtdcr 939,4");
			break;
		case 940:
			__asm__("mtdcr 940,4");
			break;
		case 941:
			__asm__("mtdcr 941,4");
			break;
		case 942:
			__asm__("mtdcr 942,4");
			break;
		case 943:
			__asm__("mtdcr 943,4");
			break;
		case 944:
			__asm__("mtdcr 944,4");
			break;
		case 945:
			__asm__("mtdcr 945,4");
			break;
		case 946:
			__asm__("mtdcr 946,4");
			break;
		case 947:
			__asm__("mtdcr 947,4");
			break;
		case 948:
			__asm__("mtdcr 948,4");
			break;
		case 949:
			__asm__("mtdcr 949,4");
			break;
		case 950:
			__asm__("mtdcr 950,4");
			break;
		case 951:
			__asm__("mtdcr 951,4");
			break;
		case 952:
			__asm__("mtdcr 952,4");
			break;
		case 953:
			__asm__("mtdcr 953,4");
			break;
		case 954:
			__asm__("mtdcr 954,4");
			break;
		case 955:
			__asm__("mtdcr 955,4");
			break;
		case 956:
			__asm__("mtdcr 956,4");
			break;
		case 957:
			__asm__("mtdcr 957,4");
			break;
		case 958:
			__asm__("mtdcr 958,4");
			break;
		case 959:
			__asm__("mtdcr 959,4");
			break;
		case 960:
			__asm__("mtdcr 960,4");
			break;
		case 961:
			__asm__("mtdcr 961,4");
			break;
		case 962:
			__asm__("mtdcr 962,4");
			break;
		case 963:
			__asm__("mtdcr 963,4");
			break;
		case 964:
			__asm__("mtdcr 964,4");
			break;
		case 965:
			__asm__("mtdcr 965,4");
			break;
		case 966:
			__asm__("mtdcr 966,4");
			break;
		case 967:
			__asm__("mtdcr 967,4");
			break;
		case 968:
			__asm__("mtdcr 968,4");
			break;
		case 969:
			__asm__("mtdcr 969,4");
			break;
		case 970:
			__asm__("mtdcr 970,4");
			break;
		case 971:
			__asm__("mtdcr 971,4");
			break;
		case 972:
			__asm__("mtdcr 972,4");
			break;
		case 973:
			__asm__("mtdcr 973,4");
			break;
		case 974:
			__asm__("mtdcr 974,4");
			break;
		case 975:
			__asm__("mtdcr 975,4");
			break;
		case 976:
			__asm__("mtdcr 976,4");
			break;
		case 977:
			__asm__("mtdcr 977,4");
			break;
		case 978:
			__asm__("mtdcr 978,4");
			break;
		case 979:
			__asm__("mtdcr 979,4");
			break;
		case 980:
			__asm__("mtdcr 980,4");
			break;
		case 981:
			__asm__("mtdcr 981,4");
			break;
		case 982:
			__asm__("mtdcr 982,4");
			break;
		case 983:
			__asm__("mtdcr 983,4");
			break;
		case 984:
			__asm__("mtdcr 984,4");
			break;
		case 985:
			__asm__("mtdcr 985,4");
			break;
		case 986:
			__asm__("mtdcr 986,4");
			break;
		case 987:
			__asm__("mtdcr 987,4");
			break;
		case 988:
			__asm__("mtdcr 988,4");
			break;
		case 989:
			__asm__("mtdcr 989,4");
			break;
		case 990:
			__asm__("mtdcr 990,4");
			break;
		case 991:
			__asm__("mtdcr 991,4");
			break;
		case 992:
			__asm__("mtdcr 992,4");
			break;
		case 993:
			__asm__("mtdcr 993,4");
			break;
		case 994:
			__asm__("mtdcr 994,4");
			break;
		case 995:
			__asm__("mtdcr 995,4");
			break;
		case 996:
			__asm__("mtdcr 996,4");
			break;
		case 997:
			__asm__("mtdcr 997,4");
			break;
		case 998:
			__asm__("mtdcr 998,4");
			break;
		case 999:
			__asm__("mtdcr 999,4");
			break;
		case 1000:
			__asm__("mtdcr 1000,4");
			break;
		case 1001:
			__asm__("mtdcr 1001,4");
			break;
		case 1002:
			__asm__("mtdcr 1002,4");
			break;
		case 1003:
			__asm__("mtdcr 1003,4");
			break;
		case 1004:
			__asm__("mtdcr 1004,4");
			break;
		case 1005:
			__asm__("mtdcr 1005,4");
			break;
		case 1006:
			__asm__("mtdcr 1006,4");
			break;
		case 1007:
			__asm__("mtdcr 1007,4");
			break;
		case 1008:
			__asm__("mtdcr 1008,4");
			break;
		case 1009:
			__asm__("mtdcr 1009,4");
			break;
		case 1010:
			__asm__("mtdcr 1010,4");
			break;
		case 1011:
			__asm__("mtdcr 1011,4");
			break;
		case 1012:
			__asm__("mtdcr 1012,4");
			break;
		case 1013:
			__asm__("mtdcr 1013,4");
			break;
		case 1014:
			__asm__("mtdcr 1014,4");
			break;
		case 1015:
			__asm__("mtdcr 1015,4");
			break;
		case 1016:
			__asm__("mtdcr 1016,4");
			break;
		case 1017:
			__asm__("mtdcr 1017,4");
			break;
		case 1018:
			__asm__("mtdcr 1018,4");
			break;
		case 1019:
			__asm__("mtdcr 1019,4");
			break;
		case 1020:
			__asm__("mtdcr 1020,4");
			break;
		case 1021:
			__asm__("mtdcr 1021,4");
			break;
		case 1022:
			__asm__("mtdcr 1022,4");
			break;
		case 1023:
			__asm__("mtdcr 1023,4");
			break;
	}
}

