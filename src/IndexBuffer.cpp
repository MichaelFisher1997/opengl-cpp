#include "IndexBuffer.h"
#include "Renderer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
  : m_Count(count)
{
  ASSERT(sizeof(unsigned int) == sizeof(GLuint));
  //
  std::cout << "m_RendererID: " << &m_RendererID << " " << m_RendererID << std::endl; 
  GLCall(glGenBuffers(1, &m_RendererID));
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); //select buffer called 'buffer'
  GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW)); // assigne buffer size, static as we use many times, but does not change
}

IndexBuffer::~IndexBuffer()
{
  std::cout << "m_RendererID: " << &m_RendererID << " " << m_RendererID << std::endl; 
  GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const  
{
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID)); //select buffer called 'buffer'
}

void IndexBuffer::Unbind() const
{
  GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); //select buffer called 'buffer'
}