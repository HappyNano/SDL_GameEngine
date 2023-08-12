#include "SGE/renderer.hpp"

SGE::Renderer::Renderer():
  _renderer{ nullptr }
{}

SGE::Renderer::Renderer(SDL_Renderer * renderer):
  _renderer{ renderer }
{}

SDL_Renderer * SGE::Renderer::get_renderer()
{
  return _renderer;
}

void SGE::Renderer::set_renderer(SDL_Renderer * renderer)
{
  _renderer = renderer;
}

void SGE::Renderer::clear()
{
  SDL_RenderClear(_renderer);
}

void SGE::Renderer::present()
{
  SDL_RenderPresent(_renderer);
}

void SGE::Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
  SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void SGE::Renderer::setDrawColor(const SDL_Color & clr)
{
  SDL_SetRenderDrawColor(_renderer, clr.r, clr.g, clr.b, clr.a);
}

SDL_Color SGE::Renderer::getDrawColor()
{
  SDL_Color tmpClr{ 0, 0, 0, 0 };
  SDL_GetRenderDrawColor(_renderer, &tmpClr.r, &tmpClr.g, &tmpClr.b, &tmpClr.a);
  return tmpClr;
}

SGE::Renderer::this_t & SGE::Renderer::drawPoint(float x, float y)
{
  SDL_RenderPoint(_renderer, x, y);
  return *this;
}

SGE::Renderer::this_t & SGE::Renderer::drawLine(float x1, float y1, float x2, float y2)
{
  SDL_RenderLine(_renderer, x1, y1, x2, y2);
  return *this;
}

SGE::Renderer::this_t & SGE::Renderer::drawRect(float x, float y, float w, float h)
{
  this->drawRect(SDL_FRect{ x, y, w, h });
  return *this;
}

SGE::Renderer::this_t & SGE::Renderer::drawRect(const SDL_FRect & rect)
{
  SDL_RenderRect(_renderer, &rect);
  return *this;
}
