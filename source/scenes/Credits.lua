CreditsScreen = {}
class('CreditsScreen').extends(ScreenBase)

function CreditsScreen:init()
  CreditsScreen.super.init(self)
  self.scroll = ScrollController(self)
  self.scroll:setStart(260)
  self.scroll:useDpad()
end

function CreditsScreen:getArtistCredits()
  local text = ''
  local credits = noteFs:getArtistCredits()
  for _, artist in pairs(credits) do
    text = text .. stringUtils:escape(artist.name) .. '\n'
    for _, link in pairs(artist.links) do
      text = text .. '_' .. stringUtils:escape(link) .. '_\n'
    end
    text = text .. '\n'
  end
  return text
end

function CreditsScreen:getCreditsText()
  local text = fsUtils:readText('./data/credits.txt')
  local artistCredits = self:getArtistCredits()
  -- replace placeholders in credits text
  text = locales:replaceKeysInText(text)
  text = stringUtils:replaceVars(text, {
    version = playdate.metadata.version,
    artistCredits = artistCredits
  })
  return text
end

function CreditsScreen:setupSprites()
  self.logo = Image(PLAYDATE_W / 2, 0, './gfx/gfx_logo_credits')
  self.logo:setAnchor('center', 'top')

  self.textView = TextView(0, self.logo.height + 12, PLAYDATE_W)

  return { self.logo, self.textView }
end

function CreditsScreen:beforeEnter()
  self.textView:setText(self:getCreditsText())
  self.scroll:setHeight(self.logo.height + 12 + self.textView.height)
  self.scroll.autoScroll = false
  self.scroll:resetOffset()
end

function CreditsScreen:afterEnter()
  self.scroll.autoScrollStep = -1.6
  self.scroll.autoScroll = true
  playdate.timer.performAfterDelay(2000, function ()
    if self.active then -- make sure that user hasn't exited since timer started
      sounds:playMusic('credits')
    end
  end)
end

function CreditsScreen:beforeLeave()
  sounds:stopMusic()
end

function CreditsScreen:drawBg()
  gfx.setColor(gfx.kColorBlack)
  gfx.fillRect(0, 0, PLAYDATE_W, PLAYDATE_H)
end

function CreditsScreen:update()
  -- auto scroll
  self.scroll:update()
end

return CreditsScreen