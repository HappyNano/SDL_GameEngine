#include "renderer.hpp"

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
