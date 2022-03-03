import 'CoreLibs/math'
import 'CoreLibs/object'
import 'CoreLibs/graphics'
import 'CoreLibs/sprites'
import 'CoreLibs/nineslice'
import 'CoreLibs/crank'
import 'CoreLibs/timer'
import 'CoreLibs/frameTimer'
import 'CoreLibs/animation'

import './utils/utils'
import './utils/stringUtils'
import './utils/fsUtils'

import './globals'

import './config'
import './locales'
import './noteFs'
import './sounds'
import './screens'

import './ui/grid'
import './ui/overlayBg'
import './ui/dialog'
import './ui/debugOverlay'

import './controllers/ScrollController'
import './controllers/FocusController'

import './components/ComponentBase'
import './components/AutoLayout'
import './components/Image'
import './components/Button'
import './components/Select'
import './components/Clock'
import './components/HomeLogo'
import './components/FolderSelect'
import './components/Thumbnail'
import './components/Timeline'
import './components/DitherSwatch'
import './components/ScrollBar'
import './components/KeyValList'
import './components/TextView'

import './screens/Screenbase'
import './screens/Home'
import './screens/NoteList'
import './screens/Details'
import './screens/Player'
import './screens/Settings'
import './screens/Dithering'
import './screens/Credits'

debug = nil -- disallow debugging

MAIN_FONT = playdate.graphics.font.new('./fonts/WhalesharkSans')
playdate.graphics.setFont(MAIN_FONT)
playdate.display.setRefreshRate(50)

-- debugOverlay:start()

config:init()
locales:init()
noteFs:init()
dialog:init()

screens:register('home',      HomeScreen())
screens:register('notelist',  NoteListScreen())
screens:register('details',   DetailsScreen())
screens:register('player',    PlayerScreen())
screens:register('settings',  SettingsScreen())
screens:register('dithering', DitheringScreen())
screens:register('credits',   CreditsScreen())

screens:push('home', screens.kTransitionStartup, screens.kTransitionFade)

function playdate.update()
  screens:update()
  playdate.graphics.sprite.update()
  playdate.timer.updateTimers()
  playdate.frameTimer.updateTimers()
  -- playdate.drawFPS(8, PLAYDATE_H - 20)
end

-- import 'CoreLibs/qrcode'
-- playdate.graphics.generateQRCode('https://playnote.studio/filehelp', 120, function (qr)
--   playdate.simulator.writeToFile(qr, '~/qr.png')
--   print('qr generated')
-- end)