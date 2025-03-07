/* ------------------------------------------------------------------------- */
/*
  Title: classification_MLP_optim, Neural Network execution code.
  Automatically generated by SNN, Wed Jan 22 11:07:57 2025


  License Agreement:
  -----------------

  Copyright StatSoft Inc., 2000-2001, all rights reserved.
  This source code (Source Code Generated by STATISTICA Neural Networks,
  referred to as "CG" below) is owned by StatSoft Inc. and is protected
  by United States Copyright laws and international treaty provisions. You
  shall treat the CG like any copyrighted material.
  The CG may not be redistributed or used except in accordance with the
  conditions below.

  The licensee is granted a license to incorporate the CG as embedded
  software in their own hardware and software products, and to distribute an
  unlimited number of such embedded copies as part of this license subject to
  obtaining prior written consent from StatSoft Inc., and subject to
  the conditions listed below.

  Prior consent is required so that StatSoft Inc. can ensure that license
  conditions are not breached, and can track legitimate use of the CG. Consent
  shall not be refused unless StatSoft Inc. reasonably believes that a
  breach of license conditions will occur. Consent shall usually be granted
  within five working days of the request, providing that sufficient details of
  the intended use are given.

  Requests should be sent to SNN Project Director, StatSoft, Inc.,
  2300 East 14th Street, Tulsa OK 74104 USA, FAX: 918-749-2217,
  E-Mail: info@statsoft.com.

  The licensee may modify the CG as they see fit for embedded use, including
  recoding into alternative programming languages, altering the neural network
  architecture and weights, and otherwise modifying the CG, provided that they
  keep intact this copyright and license notice.

  The licensee may distribute products including the compiled version of CG.

  The licensee shall not:-
    Sublicense, rent, lease, or assign any portion of the CG to third parties.
    Allow compiled versions of the CG to be incorporated in products owned
    by third parties.
    Allow access to the CG to third parties.
    Use (implicitly or explicitly) any reference to StatSoft, Inc., STATISTICA,
    STATISTICA Neural Networks, or any trade names used by StatSoft, Inc.
    to describe, promote, or reference products in which CG is used, or which
    benefit from CG.

  Except as expressly stated herein, the CG is provided "AS IS." The licensee
  shall be entirely responsible for the selection of the CG and for the
  installation, integration, use of, and results obtained from, the CG.
  In particular, but without limitation, attention is drawn to the issue of
  "limited numeric accuracy," which implies that results may not be identical to
  those when executing the same network in STATISTICA Neural Networks or through
  its Application Programming Interface.

  All other warranties or conditions, either express or implied, including but
  not limited to implied warranties of merchantability or fitness for a
  particular purpose, with respect to the CG and written information
  accompanying the CG, are excluded from the license.

  No liability for Consequential Damages. To the maximum extent permitted by
  applicable law, in no event shall StatSoft Inc.,
  or the vendor be liable for any damages whatsoever
  (including, without limitation, damages for loss of profits,
  business interruption, loss of information, or any other pecuniary loss)
  arising out of the use or inability to use this product,
  even if the vendor has been advised of the possibility of
  such damages.

  This license and your right to use the CG shall terminate automatically
  if StatSoft, Inc. determines that you violate any part of the agreement
  or if you violate any part of this agreement without the knowledge of
  StatSoft, Inc. In the event of termination, you shall immediately destroy
  all copies of the CG.

  This agreement constitutes the entire agreement between you and StatSoft Inc.,
  and supersedes any prior agreement concerning the CG. It shall
  not be modified except by written agreement dated subsequent to the date of
  this agreement signed by an authorized representative of StatSoft Inc.
  StatSoft Inc. shall not be bound by any provision of any purchase order,
  confirmation, correspondence, or otherwise, unless StatSoft Inc.
  specifically agrees to the provision in writing.

  This agreement shall be considered as a contract made in the United States
  of America and according to United States Law,
  subject to the exclusive jurisdiction of the United States Courts.
*/
/* standard includes. math.h needed for exp() function. */

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

#define MENUCODE -999


static double classification_MLP_optim02Thresholds[] =
{

/* layer 1 */
0.66615665474370167, -2.4360167938104089, -0.15930578133096621, -0.51281133452532968,
0.043235203407223512, 0.58106281011282357, -0.8174915100352671, 0.15707806654123641,
-1.1076059892592542, 2.1327614877974175, -0.16759016942249189, 1.7981454720476822,
-0.46737772652664195, 1.8455115555778667, -0.015870445243001775, 1.2808463459634849,
0.49656717569749181, -0.50040898074285889, 0.54215870312089609, 0.37501430267330499,

/* layer 2 */
0.66830634339243078, 1.0389978968910571, 1.6892541575048778, 0.96174752999958424,
0.45581117270116067, 0.077730332322549736, -1.5261335809807515, 0.26945881595542398,
0.15946343714497482, 0.95132240847057237, 0.4001017154975452, -0.3285091865444999,
1.3792074024759133, -1.0224596852305528, -1.5695708729728135, -0.19855089695276187,
1.231243495078383, -0.31716622496601532,

/* layer 3 */
0.32733592396584216

};

static double classification_MLP_optim02Weights[] =
{

/* layer 1 */
0.018350276345488255, 2.4261411899369589, -1.1229756400854747, -0.44781712279202279,
-0.15076258935459039, 0.1564922772822529, 0.34146578184361148, -0.049177283394990848,
1.33928565265572,
0.49601287056494958, -0.1359940127329172, 4.1767231883640346, -4.7237430058435912,
1.3386660642330452, 1.7949679374202563, -1.4436736269222705, -1.7683584628100044,
-4.7418199988085723,
-0.78709052494532661, -1.1334595823087075, -2.5207756266974135, 1.4357539421182568,
0.3773727806940968, 2.1065212361984398, 0.56637118556640564, 1.6337574428067645,
-2.3330903011193342,
-0.12461279091977645, -1.2558459560679847, 6.6662802829798418, -4.1946333926651533,
0.23236210578545236, 0.76002713824436463, 0.68899082299215619, 1.7380545500990074,
0.71360551136006767,
1.1084596412755003, -1.9184594234876544, 1.9712696758573307, -1.4563187843959213,
0.13219174799026681, -0.79791788803307906, 4.3215542586070841, 3.5448840452598147,
-2.8299573513995058,
-0.07982045371618432, 0.6813687035406375, 0.81723636390019283, -1.0728842761764878,
-1.1033836879789429, -0.20282615017386871, -0.78186754670200376, -0.18600199844796828,
-0.18342271860670437,
-0.11367365967951253, -0.80998669060319683, 1.6971831835107536, -1.732410764313602,
0.52929848053858286, 1.5537933189052198, -1.7074611410408043, -0.3942935921684399,
1.1323041576353512,
-1.4077847075861789, -0.58827879849789377, 2.5686155227430221, -1.5541436742411838,
-0.16128147384768357, 1.6075122619940239, 0.55616955209188257, 0.96723797725649685,
2.1427281744199589,
-1.1487245814472375, 2.866059459662059, -5.6097555713776321, 0.0892727390777346,
-0.3429526209826072, -0.94507187678539506, 1.2479689761708861, 1.5775447215584484,
-2.138427343469858,
0.85841345590560081, -3.7661320798156956, 0.85183827484360231, 0.87592577680800188,
-1.279686862279996, 1.7479116756676811, 2.1676018561336048, 2.5418419485779786,
0.27347540415242533,
0.11077599166040998, -0.13620658444975994, -2.57325989669057, -0.2438024726095484,
0.53653183983386588, 0.38232019806917256, -4.3500191051349164, -3.1157409119247386,
1.8974444377541235,
0.07955390727007923, 0.041744026760821742, -4.0387040051907732, 4.5172973995597312,
-1.2491514204693279, 1.1077089070379975, -0.57651980733197861, -0.44827077215450895,
2.916438928544645,
-1.6607849972530047, 0.27380332424154163, 0.25368481272011362, 1.7858547866297347,
-0.36688350375569001, 0.37636717915145868, 2.7754431104242729, 2.5602566698425648,
-1.1717669598337701,
1.388489507709175, -0.80989641644114485, -5.523182654063465, 2.4034462438525965,
-1.0133920879124041, 2.0593486215158117, -3.18176848503228, -2.5693894658816885,
2.8550701080301062,
-1.9634766757733142, 0.0045052262512537689, 1.0420127954406011, -1.2810444884373982,
-0.13431120390951776, 0.36940386195381564, -0.82636987822347152, 0.90866122255007653,
1.9429818233620189,
0.14159327541595038, 0.3064618834072943, -3.2423016467796688, 1.4886028880424704,
-0.62448123584390636, -0.32916199998939516, 1.2087005341031363, 1.3550407499921788,
-0.73437495432696753,
-0.48814404263565409, 1.6306010974205956, -0.37237504729876902, 1.3810905988825763,
-1.2414343255083518, 0.0056146353951673908, 5.0766182342515487, 4.3049896657890132,
-2.2982866624871017,
1.3104128529178498, 1.7244792688354598, -2.7564004522990944, -3.2070681310195717,
1.1970346389763202, -2.4384804145312198, 0.12239969177439898, 1.752643960522916,
0.67857793570282876,
0.56076288671258345, -0.76946032482329429, 3.1949739416722025, 3.1519296159780343,
0.0088594442286510887, -1.1585051339946455, 2.908817282536706, 0.21048311453484833,
-1.6339063435262082,
0.29713873155051873, 0.72552616775974466, 2.7747534125594617, -1.955033457239586,
-0.45060775501015554, 0.97325692444204437, 3.8497811249491392, 2.5161550560595569,
0.30873246357355494,

/* layer 2 */
0.3413274391373281, -0.485711438506988, -1.1300322362086721, 0.14568971132928724,
0.09274212931051963, 0.86108050095685484, -0.29068589074186957, 0.29374038924086193,
-0.57030194272936507, 1.5142467047060124, -0.76093186248038125, -0.14666969173531677,
-0.27498928028115438, 1.3653910360939412, -0.75493584879677134, 1.4366035410844908,
-0.603478693034039, 1.0521554762447958, 0.099013026589146319, 0.32461981033056708,
-0.77205029690790428, 0.027896627828161762, -0.2775193727728868, 0.1262860633592002,
-0.62032382228278404, 0.80744551189578884, 0.1388059040520204, -0.48744443449801655,
-1.0678264232429504, 0.79692579221573234, -0.84303638723691499, 0.6652625809740087,
0.39944247118292531, -0.91107755048658867, 0.89794852871407049, 0.91585831103703097,
-0.83655587457757585, 0.35229484230166636, -1.0487340428203555, 0.15078760012585993,
-0.26700117309841415, -1.170679021922471, 0.5164714276868646, 1.3385944864422594,
0.58315737625007547, 0.22039000927657543, -0.50040836855227477, 0.12453239265028725,
-0.31806354057147868, 3.1386796449518641, -0.86725141279154416, -0.45501621701328898,
0.20737739325635726, -0.42540275358599844, 1.0001266121210628, 1.5981017792221082,
0.4239892108621176, -0.8852955236671588, 0.05294176158843128, -0.12707641329834293,
-0.22198865227372433, 0.33624911348880054, -0.087481333820784143, -0.087753215863202727,
0.31792119059381002, -0.43367471995805396, -0.057142980069095857, -0.70269771089085387,
-0.21383844685249764, -0.43875349289160809, -0.40333923365384944, -1.1852505342588664,
-1.4449703531168925, 0.80056675278257483, -0.3049982538272018, 0.8391165371724848,
-1.3033773204210073, 1.435966068018895, 0.9428182965633416, -1.0662969810703249,
0.65048328490136376, -2.4661210388879473, -0.86722909196689879, 0.93392145042435393,
0.27696115979576119, -0.061365447952398879, -0.18818908045848079, 0.92440397079093073,
-0.24803890250391361, 1.3665391082225589, -0.36385830116928608, 1.5403354414925863,
-0.28497869906372314, 0.95080757729082643, 0.6028202863828217, -0.47298027157794348,
0.76282087029169221, -0.91938788730479948, 1.2370021329565901, 0.74607619272232795,
0.52017245206013685, 1.1820044247387489, 1.6847099780254891, 0.76273031530769186,
0.80854837669547364, -1.404096298732715, 1.4931427191994242, 1.1769788249176516,
-0.55815235729331547, 0.71741717287560836, 0.4666085169539852, 0.8049908885797068,
-0.21514859241176601, 0.35674070269146058, -0.076049405363285985, 0.18570413500180924,
-0.040580532753383768, -0.5696586664377592, -1.0758743876298826, 1.1667986346718167,
-0.14396688754151785, 1.9657157899208635, 1.0834341716263618, 1.4953901534215779,
0.50722865187066624, 0.66649538478335224, -0.0854478182083072, 0.81678289672301241,
0.31687952791753882, -0.95988163074086641, -1.1156210899717405, -0.72891438307493606,
-0.1060422717060905, -1.565405136314852, -0.64861504729898922, -0.98722142835136883,
-0.90840931303012529, 0.46137807385440466, -0.15850009979152613, 0.46322010223335036,
0.28228264048982671, 0.35270201660812839, -1.5842967246595823, 0.36395974808524473,
-1.9261722951733715, 1.5732815753559479, 0.88164533876053297, 1.2792222355210068,
-1.1325646311688242, -0.46188577396424996, 1.379808041350737, 0.30778147656676746,
-1.1651144833395484, 1.6991565846917629, 1.2811705107034534, -0.01790072256051109,
-2.5389913305155942, -1.1001174087185979, -0.90401691232452097, -1.1756644435001535,
0.5613863042079078, 2.1383585326837227, -0.77606416108024923, -0.044893559963692237,
-1.7646180653702599, -0.72722558715850583, 0.23972608422002864, 0.0046142337448202972,
0.26778905157905758, -0.61263345656889268, 0.65665053026374154, -0.71729500584956551,
-0.35812393206694637, 0.16614780162215431, 0.20917169512228273, -0.64808938662945625,
-1.5469832000083976, 0.76118393608955459, -0.14011878242461931, -0.93740442621941078,
0.24511461508405871, -1.653048492420081, -0.79729757183225081, -0.28379137024536821,
-1.0305039948852084, 1.1881607461556494, -0.39493967032252025, -0.34125076571035662,
-0.19063638106556219, 0.052406676937678517, 1.5213819698446298, 0.60213127341967909,
-1.6303354429899628, 2.0182351795671241, -0.98880341815360706, 1.6272914484555587,
-1.6142093950053031, 0.79211314124517385, -0.38837710605553355, -1.2671638113271968,
-0.04843988086034591, 2.0273017334080796, -1.6690741667231124, 2.3405975827900698,
0.26243757279407942, -0.31133928048067283, 1.1744827872331856, 1.1912128751762792,
-1.9698658968469784, -0.40641718271123983, 0.04587421556975578, -2.4526546732330026,
-0.45185502020359453, -1.654762597624521, 0.37576544273706403, -2.3853776616431084,
-1.2483547441739404, 0.18279803288271426, 0.080911347242448306, 1.7488709000984093,
-0.26904151157891337, 1.6938331543570788, -0.26335733687065593, 0.042726498592810205,
1.006229713005562, -0.75501746548044291, -0.98433620750466189, -0.7961289309401306,
-1.2942630668667718, -0.58290832087974642, -1.0951331122401933, -0.95551692218449935,
-0.26742498556097288, -1.4977197397085871, -1.3340739004563777, 0.97460815602724471,
0.17022602808076984, -1.8172919173678712, 2.4138409007545691, -0.030906844490918278,
-0.41506807096192155, 0.48936352977085357, -0.12381075328884524, -1.3523204754093043,
-0.36725383437812947, 1.3677168330715979, -0.14714409545175069, -1.1756049004279097,
0.21596465611563956, -0.98576925021321438, 1.3972300297590128, 0.2650079251416439,
-0.39963491556467606, 1.4940308609811996, -0.44828034027339797, -0.12073991382459558,
-0.62849080217303555, 0.39066216699099948, -0.97920743244209796, -1.1501392515761222,
-0.32078851435062411, 1.5765051421782235, 0.20099445340397934, 0.69724402729497725,
0.068696117539989429, -1.5819662885142749, 1.0813714957314615, 0.10208434186933958,
-1.3273647991991178, -1.1147739194055102, 0.24113402061465924, -0.29703844832587184,
-0.27874600797314791, -1.1786435304257052, 0.54187519890348768, -1.8767315313450721,
-0.44411781078917217, -0.24504738309229218, 0.27875934585208256, 0.039489217162244496,
0.79613521502195983, -2.9455709358587265, 0.51531110357449039, -0.97166472922540414,
-0.72620608262374309, -2.0004884728025827, 0.098796655158938332, -0.041985810207973595,
1.415534121373359, -0.50146375979099578, 0.53908122353520016, 2.2802186054758629,
0.44330667433463927, 1.2944265072597463, 0.0069022253584748068, -0.91300151900781623,
0.261559482902679, 0.54542099381891529, -0.42829220647011923, 0.25445256685153078,
0.022282240675191241, -0.18653051125841202, 0.13216841073689814, -1.2081334184835135,
-2.0712719147794112, 0.01477940451412456, 0.4141733930046772, -0.1890400627567404,
-1.2310786260217117, -0.84848802434649528, 1.1937201966920947, 0.68622268381609908,
-0.51029430797434483, 1.9820224103092063, 0.61525496143042235, -0.94917420428007693,
-1.2402092909916789, -1.631682580664783, -0.48925037898022949, -1.113660554460459,
0.80624321420421918, -2.3854455904949536, -0.98088090899752978, -1.2854315713654312,
-0.61436485065484492, 0.48787270725657622, 0.13774926282731748, 0.11894497725122503,
0.65863591500421803, -0.53414532617642829, -0.00063239950914449486, 0.26846743825097702,
-0.21050832755257487, 1.6414834425551506, 0.55015850879844297, 1.6832908759283713,
-0.43144550346022226, 1.0743016972120829, -1.1406763154065089, 0.39190421021546984,
1.1847308214379624, -1.0720524167710344, -0.97831054777154702, -0.37305926966306863,
-0.39350586385958625, -1.2621615999308911, -0.40372338819101056, -0.64749430448641254,
1.5990842278977626, -2.3597103559192281, -1.0308015882275734, -1.1759859468159253,
-0.44968038476484379, -0.1789295793931916, 0.44938235273717009, -0.88246272077004861,
0.27454786164322592, 1.6107784908680083, 0.13593764329142632, 1.1004391006113032,

/* layer 3 */
0.9515113200517743, -0.57118569722785417, -2.0094426904660687, -0.888810861885863,
-1.2304932707401577, 2.9974492511606763, 0.67556230526580929, 1.7767382801347189,
-0.92557877373152553, 1.6306929386643627, -2.1644040968962401, -1.1310628280708206,
2.1088490582689574, -2.5519654914210861, -1.7202774164702952, -1.8266375608298586,
-1.1908303950449248, 2.0426030956296466

};

static double classification_MLP_optim02Acts[96];

/* ---------------------------------------------------------- */
/*
  classification_MLP_optim02Run - run neural network classification_MLP_optim02

  inputs - the input variables of this network.
  The variable names are listed below, together with each
  variable's offset in the data set at the time code was
  generated (if the variable is then available).
  Variable (Offset)
  (f(vij))ref=<Yld(%)/c0> (2)
  Cat. Met Van der Waals radius (pm)�Cat. Met abs. min qty (�g) (cI) (3)
  DTime (h)(cI) (4)
  DReusability (min)(cI) (5)
  D.pKa base�Base  (mmol) (cII) (6)
  D.Solvent 1 dipole mom(D)�V Solvent mL (Tot) (cII) (7)
  D.Sp(Electrophile)�Electrophile  (mmol) (cII) (8)
  D.Sv(Nucleophile)�Nucleophile  (mmol) (cII) (9)
  D.Temperature (�C) (cII) (10)

*/
/* ---------------------------------------------------------- */

void classification_MLP_optim02Run( double inputs[], double outputs[], int outputType )
{
  int i, j, k, u;
  double *w = classification_MLP_optim02Weights, *t = classification_MLP_optim02Thresholds;

  /* Process inputs - apply pre-processing to each input in turn,
   * storing results in the neuron activations array.
   */

  /* Input 0: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[0] == -9999 )
    classification_MLP_optim02Acts[0] = 0.54741279188538172;
  else
    classification_MLP_optim02Acts[0] = inputs[0] * 4.1735015772870661 + -2.5552050473186121;

  /* Input 1: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[1] == -9999 )
    classification_MLP_optim02Acts[1] = 0.16989692450440483;
  else
    classification_MLP_optim02Acts[1] = inputs[1] * 1.2272197336933178e-005 + 0.17119650283976565;

  /* Input 2: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[2] == -9999 )
    classification_MLP_optim02Acts[2] = 0.10561434061764231;
  else
    classification_MLP_optim02Acts[2] = inputs[2] * 0.010471204188481676 + 0.10538394415357766;

  /* Input 3: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[3] == -9999 )
    classification_MLP_optim02Acts[3] = 0.43842173276657948;
  else
    classification_MLP_optim02Acts[3] = inputs[3] * 0.050000000000000003 + 0.43675847457627121;

  /* Input 4: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[4] == -9999 )
    classification_MLP_optim02Acts[4] = 0.86460257695619958;
  else
    classification_MLP_optim02Acts[4] = inputs[4] * 0.010770958918923833 + 0.86634412904544056;

  /* Input 5: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[5] == -9999 )
    classification_MLP_optim02Acts[5] = 0.49625788993169057;
  else
    classification_MLP_optim02Acts[5] = inputs[5] * 0.46082949308755761 + 0.49645390070922135;

  /* Input 6: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[6] == -9999 )
    classification_MLP_optim02Acts[6] = 0.23718882148593201;
  else
    classification_MLP_optim02Acts[6] = inputs[6] * 0.18253504672897194 + 0.23682726393812445;

  /* Input 7: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[7] == -9999 )
    classification_MLP_optim02Acts[7] = 0.21356830786362627;
  else
    classification_MLP_optim02Acts[7] = inputs[7] * 0.14155015492684236 + 0.21316076087231869;

  /* Input 8: standard numeric pre-processing: linear shift and scale. */
  if ( inputs[8] == -9999 )
    classification_MLP_optim02Acts[8] = 0.45641287010817805;
  else
    classification_MLP_optim02Acts[8] = inputs[8] * 0.028527370855821129 + 0.45643793369313806;

  /*
   * Process layer 1.
   */

  /* For each unit in turn */
  for ( u=0; u < 20; ++u )
  {
    /*
     * First, calculate post-synaptic potentials, storing
     * these in the classification_MLP_optim02Acts array.
     */

    /* Initialise hidden unit activation to zero */
    classification_MLP_optim02Acts[9+u] = 0.0;

    /* Accumulate weighted sum from inputs */
    for ( i=0; i < 9; ++i )
      classification_MLP_optim02Acts[9+u] += *w++ * classification_MLP_optim02Acts[0+i];

    /* Subtract threshold */
    classification_MLP_optim02Acts[9+u] -= *t++;

    /* Now apply the hyperbolic activation function, ( e^x - e^-x ) / ( e^x + e^-x ).
     * Deal with overflow and underflow
     */
    if ( classification_MLP_optim02Acts[9+u] > 100.0 )
       classification_MLP_optim02Acts[9+u] = 1.0;
    else if ( classification_MLP_optim02Acts[9+u] < -100.0 )
      classification_MLP_optim02Acts[9+u] = -1.0;
    else
    {
      double e1 = exp( classification_MLP_optim02Acts[9+u] ), e2 = exp( -classification_MLP_optim02Acts[9+u] );
      classification_MLP_optim02Acts[9+u] = ( e1 - e2 ) / ( e1 + e2 );
    }
  }

  /*
   * Process layer 2.
   */

  /* For each unit in turn */
  for ( u=0; u < 18; ++u )
  {
    /*
     * First, calculate post-synaptic potentials, storing
     * these in the classification_MLP_optim02Acts array.
     */

    /* Initialise hidden unit activation to zero */
    classification_MLP_optim02Acts[29+u] = 0.0;

    /* Accumulate weighted sum from inputs */
    for ( i=0; i < 20; ++i )
      classification_MLP_optim02Acts[29+u] += *w++ * classification_MLP_optim02Acts[9+i];

    /* Subtract threshold */
    classification_MLP_optim02Acts[29+u] -= *t++;

    /* Now apply the hyperbolic activation function, ( e^x - e^-x ) / ( e^x + e^-x ).
     * Deal with overflow and underflow
     */
    if ( classification_MLP_optim02Acts[29+u] > 100.0 )
       classification_MLP_optim02Acts[29+u] = 1.0;
    else if ( classification_MLP_optim02Acts[29+u] < -100.0 )
      classification_MLP_optim02Acts[29+u] = -1.0;
    else
    {
      double e1 = exp( classification_MLP_optim02Acts[29+u] ), e2 = exp( -classification_MLP_optim02Acts[29+u] );
      classification_MLP_optim02Acts[29+u] = ( e1 - e2 ) / ( e1 + e2 );
    }
  }

  /*
   * Process layer 3.
   */

  /* For each unit in turn */
  for ( u=0; u < 1; ++u )
  {
    /*
     * First, calculate post-synaptic potentials, storing
     * these in the classification_MLP_optim02Acts array.
     */

    /* Initialise hidden unit activation to zero */
    classification_MLP_optim02Acts[47+u] = 0.0;

    /* Accumulate weighted sum from inputs */
    for ( i=0; i < 18; ++i )
      classification_MLP_optim02Acts[47+u] += *w++ * classification_MLP_optim02Acts[29+i];

    /* Subtract threshold */
    classification_MLP_optim02Acts[47+u] -= *t++;

    /* Now apply the logistic activation function, 1 / ( 1 + e^-x ).
     * Deal with overflow and underflow
     */
    if ( classification_MLP_optim02Acts[47+u] > 100.0 )
       classification_MLP_optim02Acts[47+u] = 1.0;
    else if ( classification_MLP_optim02Acts[47+u] < -100.0 )
      classification_MLP_optim02Acts[47+u] = 0.0;
    else
      classification_MLP_optim02Acts[47+u] = 1.0 / ( 1.0 + exp( - classification_MLP_optim02Acts[47+u] ) );
  }

  /* Type of output required - selected by outputType parameter */
  switch ( outputType )
  {
    /* The usual type is to generate the output variables */
    case 0:


      /* Post-process output 0, two-state nominal output */
      if ( classification_MLP_optim02Acts[47] >= 0.45478254034914645 )
        outputs[0] = 2.0;
      else
        outputs[0] = 1.0;
      break;

    /* type 1 is activation of output neurons */
    case 1:
      for ( i=0; i < 1; ++i )
        outputs[i] = classification_MLP_optim02Acts[47+i];
      break;

    /* type 2 is codebook vector of winning node (lowest actn) 1st hidden layer */
    case 2:
      {
        int winner=0;
        for ( i=1; i < 20; ++i )
          if ( classification_MLP_optim02Acts[9+i] < classification_MLP_optim02Acts[9+winner] )
            winner=i;

        for ( i=0; i < 9; ++i )
          outputs[i] = classification_MLP_optim02Weights[9*winner+i];
      }
      break;

    /* type 3 indicates winning node (lowest actn) in 1st hidden layer */
    case 3:
      {
        int winner=0;
        for ( i=1; i < 20; ++i )
          if ( classification_MLP_optim02Acts[9+i] < classification_MLP_optim02Acts[9+winner] )
            winner=i;

        outputs[0] = winner;
      }
      break;
  }
}

/* ---------------------------------------------------------- */
/*
  classification_MLP_optim02RunPadded - run model classification_MLP_optim02

  inputs - the input variables, in the same number and order
  as in the data set at the time the code was generated.
  This alternative routine is useful if you want a consistent
  interface for your generated routines, so that the number
  and order of variables is the same for all of them.
  Variables (ones used as inputs marked thus *):
  0)	Yield
  1)	Set
  2)	(f(vij))ref=<Yld(%)/c0> *
  3)	Cat. Met Van der Waals radius (pm)�Cat. Met abs. min qty (�g) (cI) *
  4)	DTime (h)(cI) *
  5)	DReusability (min)(cI) *
  6)	D.pKa base�Base  (mmol) (cII) *
  7)	D.Solvent 1 dipole mom(D)�V Solvent mL (Tot) (cII) *
  8)	D.Sp(Electrophile)�Electrophile  (mmol) (cII) *
  9)	D.Sv(Nucleophile)�Nucleophile  (mmol) (cII) *
  10)	D.Temperature (�C) (cII) *

*/
/* ---------------------------------------------------------- */

void classification_MLP_optim02RunPadded( double inputs[], double outputs[], int outputType )
{
  double in[9];

  /* Copy inputs */
  in[0]=inputs[2];
  in[1]=inputs[3];
  in[2]=inputs[4];
  in[3]=inputs[5];
  in[4]=inputs[6];
  in[5]=inputs[7];
  in[6]=inputs[8];
  in[7]=inputs[9];
  in[8]=inputs[10];


  /* Run the network */
  classification_MLP_optim02Run( in, outputs, outputType );
}


/*
  Test harness. Compile including this main() procedure, as
  a windows console program or a DOS program, to interactively
  test that the software functions as expected.
*/

void main(void)
{
  int i, outputType=0, noOutputs=1;
  double inputs[9], outputs[9];

  printf( "\n\nclassification_MLP_optim test harness program. Enter inputs below\n" );
  printf( "Nominal variables should be numbered starting at 1 (0 for missing)\n" );
  printf( "(e.g. if an input is Gender={male,female}, enter 1 for male, 2 for female)\n" );

  /* Infinite (user-breakable) loop for repeated tests */
start_of_loop:
  while ( 1 )
  {
    /* Get the input pattern */
    for ( i=0; i < 9; ++i )
    {
      printf( "Enter value for input %d: ", i+1 );
      scanf( "%lg", & inputs[i] );

      /* Check for sub-menu */
      if ( inputs[i] == MENUCODE )
      {
        printf( "Control menu. Select output style, or exit:\n" );
        printf( "0. Normal output style (output variable)\n" );
        printf( "1. Output layer activations\n" );
        printf( "2. Codebook vector (usual only for Kohonen networks\n" );
        printf( "3. Winning hidden neuron (ditto only Kohonen)\n" );
        printf( "4. Exit program\n" );
        printf( "> " );
        scanf( "%d", & outputType );
        if ( outputType < 0 || outputType > 3 )
        {
          printf( "\nBye.\n" );
          return;
        }
        else
        {
          /* Determine how many outputs there are to display (depends on
           * output type)
           */
          switch ( outputType )
          {
            case 0:
              noOutputs = 1;
              break;

            case 1:
              noOutputs = 1;
              break;

            case 2:
              noOutputs = 9;
              break;

            case 3:
              noOutputs = 1;
              break;
          }
          goto start_of_loop;
        }
      }
    }

    /* Run the neural network */
    classification_MLP_optim02Run( inputs, outputs, outputType );

    /* Display the output of the neural network */
    printf( "\n\nOutput of neural network:\n" );

    for ( i=0; i < noOutputs; ++i )
    {
      printf( "Output %d: ", i+1 );
      printf( "%g\n", outputs[i] );
    }

    printf( "\nEnter next input pattern (for control menu inc. exit, enter %d for any input):\n", MENUCODE );
  }
}
